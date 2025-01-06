using namespace std;

#include <iostream>
#include <cstdlib>
#include <cassert>

/*
#####################################################################

? g++ <FILENAME>.cpp -o <FILENAME> && ./<FILENAME>

#####################################################################

!HEADER FILE: |Tail.h|

#ifndef TAIL_H
#define TAIL_H

#include <iostream>

using namespace std;

void foo();

#endif // TAIL_H

-------------------------------

!HEADER CODE: |Tail.cpp|

#include "tail.h"

void foo()
{
    return bar;
}

-------------------------------

!CPP FILE: |file.cpp|

#include "tail.h"

using namespace std;

int main()
{
    foo();
}

-------------------------------

? g++ <FILENAME>.cpp <HEADERNAME>.cpp -o <FILENAME> && ./<FILENAME>

#####################################################################

! Cancella con DELETE tutti i puntatori

#####################################################################

 COME INTERPRETARE UN FILE DIMACS:

! HEADER:
*   p cnf <numero di clausole> <numero di variabili>
?   numero di clausole: sono le righe sul file
?   numero di variabili: è il numero massimo di x esempio se nVar=3 => x1,x2,x3

*  es.
  p cnf 2 3
? 2 indica che ci sono 2 righe nel file.
? 3 indica che ci sono 3 variabili x1,x2,x3

! CLAUSOLE :
* il primo numero della riga è il numero di letterali che compongono la clausola

  es.2 6 5 = >
? 2 è il numero di letterali

? il meno davanti a un numero indica che quella variabile è negata
 es.2 -6 5 = > x6 è negato

? Se non ci sono indicazioni diverse ogni numero sulla riga è OR con il successivo :
 es.2 -6 5 = > not(x6) OR x5

? Se non ci sono indicazioni diverse ogni riga è AND con la successiva
 es. 2 -6 5
     3 1 2 3 = > (not(x6) OR x5)AND(x1 OR x2 OR x3)

#####################################################################

*/
namespace rov
{
    typedef struct List
    {
        int data;
        struct List *next;
    } List;

    typedef struct Queue
    {
        List *head;
        List *tail;
    } Queue;

    Queue *initQueue()
    {
        return new Queue{nullptr, nullptr};
    }

    bool isEmpty(Queue *s)
    {
        return ((s != nullptr) && (s->head == s->tail) && (s->head == nullptr));
    }

    void enqueue(Queue *&s, int value)
    {
        if (s == nullptr)
        {
            std::cerr << "enqueue Error: the queue is nullptr" << std::endl;
            assert(false);
            exit(1);
        }
        List *newElement = new List{value, nullptr};
        if (isEmpty(s))
        {
            s->tail = s->head = newElement;
        }
        else
        {
            s->tail->next = newElement;
            s->tail = newElement;
        }
    }

    int first(Queue *s)
    {
        if (isEmpty(s))
        {
            std::cerr << "first Error: the queue is empty" << std::endl;
            assert(false);
            exit(1);
        }
        return s->head->data;
    }

    int dequeue(Queue *&s)
    {
        if (isEmpty(s))
        {
            std::cerr << "dequeue Error: queue is empty" << std::endl;
            assert(false);
            exit(1);
        }
        int value = s->head->data;
        List *temp = s->head;
        if (s->head == s->tail)
        {
            s->head = s->tail = nullptr;
        }
        else
        {
            s->head = s->head->next;
        }
        delete temp;
        return value;
    }

    int length(Queue *s)
    {
        int count = 0;
        List *temp = s->head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void reverse(Queue *&s)
    {
        if (!isEmpty(s))
        {
            int v = dequeue(s);
            reverse(s);
            enqueue(s, v);
        }
    }

    void deleteQueue(Queue *&s)
    {
        while (!isEmpty(s))
        {
            dequeue(s);
        }
    }

    void printQueue(Queue *s, const char *message = "Queue: ")
    {
        if (isEmpty(s))
        {
            std::cout << message << "Queue is empty" << std::endl;
        }
        else
        {
            std::cout << message;
            List *temp = s->head;
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

    typedef struct Stack
    {
        int data;
        struct Stack *next;
    } Stack;

    struct Stack *initStack()
    {
        return nullptr;
    }

    bool isEmpty(struct Stack *s)
    {
        return (s == nullptr);
    }

    void push(struct Stack *&s, int value)
    {
        struct Stack *newElement = new Stack;
        newElement->data = value;
        newElement->next = s;
        s = newElement;
    }

    int top(struct Stack *s)
    {
        if (isEmpty(s))
        {
            std::cerr << "top Error: stack is empty" << std::endl;
            assert(false);
            exit(1);
        }
        return s->data;
    }

    int pop(struct Stack *&s)
    {
        if (isEmpty(s))
        {
            std::cerr << "pop Error: stack is empty" << std::endl;
            assert(false);
            exit(1);
        }
        int value = s->data;
        struct Stack *temp = s;
        s = s->next;
        delete temp;
        return value;
    }

    int lenght(struct Stack *s)
    {
        int count = 0;
        struct Stack *temp = s;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteStack(struct Stack *&s)
    {
        while (!isEmpty(s))
        {
            pop(s);
        }
    }

    void printStack(struct Stack *s, const char *message = "Stack: ")
    {
        if (isEmpty(s))
        {
            std::cout << "Stack is empty" << std::endl;
        }
        else
        {
            std::cout << message;
            struct Stack *temp = s;
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

} // namespace rov

namespace que
{
    using namespace rov;

    int GetAtIndex_Que(Queue *&q, int i, int pos = 0)
    {
        int res;
        if (isEmpty(q))
            return res;
        int n = dequeue(q);
        if (i == 0)
        {
            res = n;
            GetAtIndex_Que(q, i - 1, pos + 1);
        }
        else
            res = GetAtIndex_Que(q, i - 1, pos + 1);
        enqueue(q, n);
        if (pos == 0)
            reverse(q);
        return res;
    }

    void RemoveAtIndex_Que(Queue *&q, int i, int pos = 0)
    {
        if (isEmpty(q))
            return;
        int n = dequeue(q);
        RemoveAtIndex_Que(q, i - 1, pos + 1);

        if (i != 0)
            enqueue(q, n);

        if (pos == 0)
            reverse(q);
    }

    int LengthRecursive_Que(Queue *&q, int ctr = 0)
    {
        if (isEmpty(q))
            return ctr;
        int v = dequeue(q);
        ctr++;
        int res = LengthRecursive_Que(q, ctr);
        enqueue(q, v);
        if (ctr == 0)
            reverse(q);
        return res;
    }

    void Sort_Que(Queue *&q, int qsize)
    {
        if (isEmpty(q) || qsize == 0)
            return;
        int tmp = first(q);
        dequeue(q);
        Sort_Que(q, qsize - 1);
        enqueue(q, tmp);
    }
} // namespace que

namespace sta
{
    using namespace rov;

    void Reverse_Sta(struct Stack *&s)
    {
        if (!isEmpty(s))
        {
            int v = pop(s);
            Reverse_Sta(s);
            push(s, v);
        }
    }

    int GetAtIndex_Sta(Stack *s, int i, int pos = 0)
    {
        if (isEmpty(s))
            return -1;
        int n = pop(s);
        if (i == 0)
        {
            push(s, n);
            return n;
        }
        int res = GetAtIndex_Sta(s, i - 1, pos + 1);
        push(s, n);
        if (pos == 0)
            Reverse_Sta(s);
        return res;
    }

    void RemoveAtIndex_Sta(Stack *&s, int i, int pos = 0)
    {
        if (isEmpty(s))
            return;
        int n = pop(s);
        RemoveAtIndex_Sta(s, i - 1, pos++);
        if (i != 0)
            push(s, n);
        if (pos == 0)
            Reverse_Sta(s);
    }

    int LengthRecursive_Sta(Stack *&s, int ctr = 0)
    {
        if (isEmpty(s))
            return ctr;
        int v = pop(s);
        ctr++;
        int res = LengthRecursive_Sta(s, ctr);
        push(s, v);
        if (ctr == 0)
            Reverse_Sta(s);
        return res;
    }

    void FirstToLast_Sta(Stack *&s, int ssize)
    {
        if (isEmpty(s) || ssize == 0)
            return;
        int tmp = top(s);
        pop(s);
        FirstToLast_Sta(s, ssize - 1);
        push(s, tmp);
    }

    void Sort_Sta(Stack *&s, int ssize)
    {
        if (isEmpty(s) || ssize == 0)
            return;
        FirstToLast_Sta(s, ssize);
        int tmp = top(s);
        pop(s);
        Sort_Sta(s, ssize - 1);
        push(s, tmp);
    }

} // namespace sta
