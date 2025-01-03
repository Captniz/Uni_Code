    printQueue(result, "Result of calcola: ");
    printQueue(s, "Original after: ");
    deleteQueue(s);
    deleteQueue(result);

    s = initQueue();
    for (int i = 0; i < 10; i++)
    {
        enqueue(s, rand() % 10);
    }
    enqueue(s, 7);
    printQueue(s, "Original before: ");
    result = calcola(s);
    printQueue(result, "Result of calcola: ");
    printQueue(s, "Original after: ");
    deleteQueue(s);
    deleteQueue(result);

    s = initQueue();
    result = calcola(s);
    printQueue(result, "Result of calcola: ");
    printQueue(s, "Original after: ");
    deleteQueue(s);
    deleteQueue(result);

    return 0;
}

// Inserire qui sotto la definizione della funzione calcola
Queue *calcola(Queue *&q)
{
    Queue *nq = new Queue();
    int len = length(q);
    int arr[10];