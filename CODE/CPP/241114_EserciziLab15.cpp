using namespace std;

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Snippets/Snippets.hpp"

int Uno(char str[])
{
    int sum = 0;
    int len = str::Length_Str(str);

    for (int i = 0; i < len; i++)
    {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
        {
            return -1;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    for (int i = 1; i < len; i++)
    {
        sum += (str[i] - 97) - (str[i - 1] - 97);
    }

    return sum;
}

void Due(int argc, char *argv[])
{
    switch (argv[3][0])
    {
    case '+':
        cout << atoi(argv[1]) + atoi(argv[2]) << endl;
        break;

    case '-':
        cout << atoi(argv[1]) - atoi(argv[2]) << endl;
        break;

    case '*':
        cout << atoi(argv[1]) * atoi(argv[2]) << endl;
        break;

    case '/':
        cout << atoi(argv[1]) / atoi(argv[2]) << endl;
        break;

    default:
        cout << "Operazione non valida." << endl;
        break;
    }
}

void Tre()
{
    fstream in, out;

    in = fstream("input.txt", ios::in);
    out = fstream("output.txt", ios::out);

    if (!in.is_open() || !out.is_open())
    {
        cout << "Errore nell'apertura del file." << endl;
        return;
    }

    while (!in.eof())
    {
        // cout << (char)in.get();
        char str[256];
        in >> str;
        cout << str << ' ';
    }

    in.close();
    out.close();
}

void Cinque(char l)
{
    fstream in, out;

    in = fstream("input.txt", ios::in);
    out = fstream("output.txt", ios::out);

    if (!in.is_open() || !out.is_open())
    {
        cout << "Errore nell'apertura del file." << endl;
        return;
    }

    char ch = in.get();
    while (ch != EOF)
    {
        out << (ch == l ? '*' : ch);
        ch = in.get();
    }

    in.close();
    out.close();
}

int main(int argc, char *argv[])
{
}