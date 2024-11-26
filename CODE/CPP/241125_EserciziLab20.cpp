using namespace std;

#include <iostream>
#include <fstream>
#include "Snippets/Snippets.hpp"

using namespace stc;
using namespace mix;

void Uno()
{
    fstream in = OpenFile_Mix("input.txt", ios::in);
    fstream out = OpenFile_Mix("output.txt", ios::out);
    Stack_Stc<int> stack = Stack_Stc<int>();

    char line[100];

    while (!in.eof())
    {
        in.getline(line, 100);
        stack.Push(atoi(line));
    }

    stack.Print();

    while (!stack.IsEmpty())
    {
        out << stack.PopV() << endl;
    }

    stack.Print();

    in.close();
    out.close();
    stack.~Stack_Stc();
}

void Due()
{
    fstream in = fstream("input.txt", ios::in);
    int ctr = 0;

    char c;
    int last = 0;
    while (in.get(c) && ctr >= 0)
    {
        if (c == '(')
        {
            ctr++;
        }
        else if (c == ')')
        {
            ctr--;
        }
    }

    if (ctr == 0)
    {
        cout << "Parenthesis balanced" << endl;
    }
    else
    {
        cout << "Parenthesis not balanced" << endl;
    }
}

void Tre()
{
    Queue_Stc<char *> coda = Queue_Stc<char *>();
    char *nome = new char[100];

    while (true)
    {
        int opt = InputInt_Mix("Scegli un opzione:\n1. Inserisci persona\n2. Rimuovi persona\n3. Stampa\n4. Esci\n");

        cout << endl;

        switch (opt)
        {
        case 1:

            nome = InputString_Mix("Inserisci il nome della persona: ");

            if (coda.Find(nome))
            {
                cout << "Persona già presente" << endl;
                break;
            }
            else
            {
                coda.Enqueue(nome);
            }

            break;

        case 2:
            cout << "Rimosso: " << coda.DequeueV() << endl;
            break;

        case 3:
            coda.Print();
            break;

        case 4:
            return;

        default:
            cout << "Opzione non valida" << endl;
            break;
        }

        cout << endl
             << "Premi un tasto per continuare...";
        getchar();
        getchar();
        system("clear");
    }
}

void Quattro()
{
    int tmp[] = {1, 2, 3, 4, 5};
    Stack_Stc<int> stack = Stack_Stc<int>(tmp, 5);
    Queue_Stc<int> queue = Queue_Stc<int>();

    stack.Print();

    while (!stack.IsEmpty())
    {
        queue.Enqueue(stack.PopV());
    }

    while (!queue.isEmpty())
    {
        stack.Push(queue.DequeueV());
    }

    stack.Print();
}

void Cinque()
{
    char str[] = "negen";
    Stack_Stc<char> stack = Stack_Stc<char>();

    while (str[stack.Size()] != '\0')
    {
        stack.Push(str[stack.Size()]);
    }

    int ctr = 0;
    while (!stack.IsEmpty())
    {
        cout << stack.TopV() << " " << str[ctr] << endl;
        if (stack.PopV() == str[ctr])
        {
            ctr++;
        }
        else
        {
            cout << "Not palindrome" << endl;
            return;
        }
    }

    cout << "Palindrome" << endl;
    return;
}

int main(int argc, char *argv[])
{
    Tre();
    return 0;
}