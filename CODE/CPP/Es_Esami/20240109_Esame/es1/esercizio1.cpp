// Allowed include
#include <iostream>
#include <fstream>

// Add your code hereafter

using namespace std;

void elaborariga(char *riga, int (&num)[13], int &ris);
int converti(char *b, int n);
int somma(int (&num)[13], int len);

int main(int argc, char const *argv[])
{
    fstream in = fstream("input.txt", ios::in);
    fstream out = fstream("output.txt", ios::out);
    char **text = new char *[100];

    if (!in.is_open() || !out.is_open())
    {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }

    int i = 0;
    while (!in.eof())
    {
        text[i] = new char[150];
        in.getline(text[i], 150);
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        int num[13];
        int ris;
        elaborariga(text[j], num, ris);
        if (somma(num, 13) != ris)
            out << "Errore" << endl;
        else
            out << ris << endl;
    }

    in.close();
    out.close();
    return 0;
}

void elaborariga(char *riga, int (&num)[13], int &ris)
{
    char num_bin[8];
    int i = 0;
    int j = 0;
    int len = 0;

    while (riga[i] != '=')
    {
        if (riga[i] == '+')
        {
            num[j] = converti(num_bin, len);
            len = 0;
            j++;
            i++;
            continue;
        }

        num_bin[len] = riga[i];
        len++;
        i++;
    }
    num[j] = converti(num_bin, len);
    len = 0;
    j++;
    i++;

    if (j != 13)
    {
        for (j = j; j < 13; j++)
            num[j] = 0;
    }

    while (riga[i] != ';')
    {
        num_bin[len] = riga[i];
        len++;
        i++;
    }

    ris = converti(num_bin, len);
}

int converti(char *b, int n)
{
    int base = 1;
    int dec = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i] == '1')
        {
            dec += base;
        }
        base *= 2;
    }
    return dec;
}

int somma(int (&num)[13], int len)
{
    int somma = 0;
    for (int i = 0; i < len; i++)
    {
        somma += num[i];
    }
    return somma;
}