#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define T 3

int ctr = 0;

typedef struct
{
    int *arr;
    int start;
    int end;
} thread_args;

void *thread_func(void *args)
{
    int start = ((thread_args *)args)->start;
    int end = ((thread_args *)args)->end;
    int *arr = ((thread_args *)args)->arr;

    printf("Thread %ld: start %d, end %d\n", (long)pthread_self(), start, end);
    for (int i = start; i <= end; i++)
        ctr += arr[i];
}

int main(int argc, char const *argv[])
{
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    pthread_t threads[T];
    thread_args args[T];
    for (int i = 0; i < T; i++)
    {
        args[i].arr = vec;
        args[i].start = i * 3;
        args[i].end = i * 3 + 2;

        pthread_create(&threads[i], NULL, thread_func, (void *)&args[i]);
    }

    for (int i = 0; i < T; i++)
        pthread_join(threads[i], NULL);

    int excp = 0;
    for (int i = 0; i < 9; i++)
        excp += vec[i];

    printf("Attuali : %d\n", ctr);
    printf("Attesi : %d\n", excp);
    return 0;
}
