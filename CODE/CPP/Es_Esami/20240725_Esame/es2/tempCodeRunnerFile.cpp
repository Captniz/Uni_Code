void calcola(Queue *&q1, Queue *&q2, int pos)
{
    if (length(q1) == 0)
        return;

    if (pos == 0)
        reverse(q2);

    int v2 = dequeue(q2);
    int v1 = dequeue(q1);

    int sum = v2 + v1;

    enqueue(q1, sum);
    enqueue(q2, v2);

    if (pos == length(q1) - 1)
        reverse(q2);
    else
        calcola(q1, q2, pos + 1);
}