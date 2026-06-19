#define _POSIX_C_SOURCE 200809L

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <signal.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

#include "giocatore.c"
typedef struct
{
    pid_t pid;
    int32_t pipe[2];
    int16_t wins;

} player;

void player_init(player *pl, pid_t checker_pid, char *settings_path, int queue_id)
{
    close(pl->pipe[PIPE_READ]);
    player_main(pl->pipe[PIPE_WRITE], checker_pid, settings_path, queue_id);
}

int compar(const void *a, const void *b)
{
    int x = *((int *)a);
    int y = *((int *)b);

    if (x == y)
        return 0;

    if (x < y)
        return -1;
    return 1;
}

void fill_hand(pid_t player_pid, hand_t *hand)
{
    hand->mtype = (long)player_pid;
    for (int i = 0; i < NUM_CARDS; i++)
        hand->cards[i] = rand() % 9 + 1;

    qsort(hand->cards, NUM_CARDS, sizeof(hand->cards[0]), compar);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    pid_t checker_pid;
    FILE *settings;

    //===================== CHECKS
    if (argc != 3)
        return 40;

    checker_pid = atoi(argv[2]);
    // if (checker_pid == 0 || kill(checker_pid, 0) == -1)
    //     return 40;

    settings = fopen(argv[1], "r");
    if (!settings)
        return 41;

    //===================== VARS

    int player_count;
    key_t queue_key;
    int queue_id;
    pid_t winner_pid = 0;
    int16_t winner_wins = 0;

    fscanf(settings, "%d", &player_count);
    if (player_count > MAX_PLAYERS || player_count < 2)
        return 42;

    //===================== MESSAGEQUEUE
    queue_key = ftok(argv[0], player_count);
    queue_id = msgget(queue_key, 0666 | IPC_CREAT);

    if (queue_id == -1)
        return 43;

    fclose(settings);

    //===================== CHILDS

    player players[player_count];

    for (int i = 0; i < player_count; i++)
    {
        players[i].wins = 0;
        pipe(players[i].pipe);

        players[i].pid = fork();

        if (players[i].pid == 0)
            // Child
            player_init(&players[i], checker_pid, argv[1], queue_id);

        // Father
        close(players[i].pipe[PIPE_WRITE]);

        hand_t player_hand;
        fill_hand(players[i].pid, &player_hand);
        msgsnd(queue_id, &player_hand, sizeof(player_hand.cards), 0);
    }

    //============ GAME

    sleep(1);
    for (int rounds = 0; rounds < NUM_CARDS; rounds++)
    {
        int max = 0;
        pid_t round_winner_pid = 0;
        for (int i = 0; i < player_count; i++)
        {
            int card = 0;
            kill(players[i].pid, SIGUSR1);
            read(players[i].pipe[PIPE_READ], &card, sizeof(int));
            printf("Player with pid %d played %d\n", players[i].pid, card);

            if (card > max)
            {
                max = card;
                round_winner_pid = players[i].pid;
            }
            else if (card == max && round_winner_pid < players[i].pid)
                round_winner_pid = players[i].pid;
        }

        fprintf(stderr, "Player with pid %d won the round with card %d\n\n\n", round_winner_pid, max);

        for (int i = 0; i < player_count; i++)
            if (players[i].pid == round_winner_pid)
            {
                players[i].wins++;
                if (players[i].wins > winner_wins)
                {
                    winner_wins = players[i].wins;
                    winner_pid = players[i].pid;
                }
                break;
            }
    }

    //===================== WINNER

    union sigval value;
    value.sival_int = winner_wins;
    sigqueue(winner_pid, SIGUSR2, value);
    waitpid(winner_pid, NULL, 0);

    //===================== CLEANUP

    for (int i = 0; i < player_count; i++)
    {
        close(players[i].pipe[PIPE_READ]);
        kill(players[i].pid, SIGKILL);
    }

    return 0;
}

//! SLEEP DOPO DI INIT CHILD
//! NIENTE VAI NEI HANDLER
//! PIPE WRITE = 1
//! IMPORTANTE PER POSIX : _POSIX_C_SOURCE 200809L
//! SINSTASSI SORT
/*
qsort(hand->cards, NUM_CARDS, sizeof(hand->cards[0]), compar);

int compar(const void *a, const void *b)
{
    int x = *((int *)a);
    int y = *((int *)b);

    if (x == y)
        return 0;

    if (x < y)
        return -1;
    return 1;
}
*/
//! PER IL RANDOM srand(time(NULL)); SOLO ALL'INIZIO DEL MAIN, NON DENTRO IL CICLO
//! SINTASSI SORT : rand() % (max-min+1) + min;
//! argv[0] = path eseguibile
//! cleanup : CHIUDI PIPE (close) E KILL (kill) TUTTI I FIGLI, ANCHE QUELLO CHE HA VINTO E LIBERA I PUNTATORI (free)
//! UTILIZZA pause() E VARIABILI GLOBALI LAVORANDO COI SIGNALS