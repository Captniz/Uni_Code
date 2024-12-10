using namespace std;

#include <iostream>
#include <fstream>
#include "Snippets/Snippets.hpp"

struct Node
{
private:
    int data;
    Node *next;

public:
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    int GetData()
    {
        return data;
    }

    void SetData(int data)
    {
        this->data = data;
    }

    Node *GetNext()
    {
        return next;
    }

    void SetNext(Node *next)
    {
        this->next = next;
    }
};

void PrintList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->GetData() << " ";
        current = current->GetNext();
    }
    cout << endl;
}

void DestroyList(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->GetNext();
        delete temp;
    }
}

void PrintReverseList(Node *head)
{
    if (head->GetNext() != nullptr)
    {
        PrintReverseList(head->GetNext());
    }
    cout << head->GetData() << " ";
}

bool IsPrime(int n)
{
    if (n <= 1)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void PrimeList(Node *head)
{
    Node *curr = head;

    do
    {
        if (!IsPrime(curr->GetData()))
        {
            if (curr->GetNext() == nullptr)
            {
                curr->SetData(0);
                curr->SetNext(nullptr);
            }
            else
            {
                curr->SetData(curr->GetNext()->GetData());
                curr->SetNext(curr->GetNext()->GetNext());
            }
        }
        else
        {
            curr = curr->GetNext();
        }
    } while (curr != nullptr);
}

void Uno()
{
    fstream in("input.txt", ios::in);
    Node *head = new Node();
    Node *current = head;

    if (!in)
    {
        cout << "Errore apertura file" << endl;
        return;
    }

    {
        int n;
        char s[100];
        in.getline(s, 100);
        n = atoi(s);
        current->SetData(n);
    }

    while (!in.eof())
    {
        current->SetNext(new Node());
        current = current->GetNext();
        char s[100];
        int n;
        in.getline(s, 100);
        n = atoi(s);
        current->SetData(n);
    }

    PrintList(head);
    PrintReverseList(head);
    cout << endl;
    PrimeList(head);
    PrintList(head);
    DestroyList(head);
}

int main(int argc, char *argv[])
{
    Uno();
}