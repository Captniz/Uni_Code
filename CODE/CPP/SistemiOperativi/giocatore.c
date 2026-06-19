#define _POSIX_C_SOURCE 200809L

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "gioco.h"

volatile sig_atomic_t gioca = 0;
volatile sig_atomic_t won = 0;
int won_score = 0;
FILE *settings;

void mio_turno(int signo)
{
    gioca = 1;
}

void vittoria(int signo, siginfo_t *info, void *empty)
{
    (void)signo;
    (void)empty;
    won_score = info->si_value.sival_int;
    won = 1;
}

void player_main(int pipe_write_fd, pid_t checker_pid,
                 const char *settings_path, int queue_id)
{
    //============== INIT

    pid_t mypid = getpid();
    hand_t hand;
    int hand_ctr = 0;

    msgrcv(queue_id, &hand, sizeof(hand.cards), mypid, 0);
    
    // union sigval value;
    // value.sival_int = hand.cards[9];
    //  sigqueue(checker_pid, SIGRTMIN, value);

    //=============== SIGNALS
    struct sigaction sa;

    sa.sa_handler = mio_turno;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);

    struct sigaction sb;
    sb.sa_sigaction = vittoria;
    sigemptyset(&sb.sa_mask);
    sb.sa_flags = SA_SIGINFO; // Use sa_sigaction
    sigaction(SIGUSR2, &sb, NULL);
    
    //=============== TURNO

    for (;;)
    {
        pause();

        if (won)
        {
            settings = fopen(settings_path, "w");
            fprintf(settings, "%ld-%d", (long)getpid(), won_score);
            fclose(settings);
            close(pipe_write_fd);
            exit(0);
        }

        if (gioca)
        {
            write(pipe_write_fd, &hand.cards[hand_ctr], sizeof(int));
            hand_ctr += 1;
        }
        gioca = 0;
    }

    //=============== EXIT

    exit(0);
}