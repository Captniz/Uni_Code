using namespace std;

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Snippets/Snippets.hpp"

void Uno()
{

    fstream in, out;
    in.open("input.txt", ios::in);
    out.open("output.txt", ios::out);

    if (!in || !out)
    {
        cout << "Errore apertura file di input" << endl;
        return;
    }

    int pas = mix::InputInt_Mix("Inserisci i passi del cifrario: ");
    char c = in.get();

    while (c != EOF)
    {
        if (c > 64 && c < 91)
        {
            c = 65 + ((c - 65 + pas) % 26);
        }
        else if (c > 96 && c < 123)
        {
            c = 97 + ((c - 97 + pas) % 26);
        }

        out << c;
        c = in.get();
    }
}

char *Due(char str[], int pos = 0, int upper = 0)
{

    if (str[pos] == '\0')
    {
        char *ret = str::Substr_Str(str, upper, pos);
        str[upper] = '\0';
        return ret;
    }

    if (str[pos] > 64 && str[pos] < 91) // se è maiuscola
    {
        return Due(str, pos + 1, upper);
    }
    else
    {
        char tmp;
        tmp = str[pos];
        str[pos] = str[upper];
        str[upper] = tmp;
        return Due(str, pos + 1, upper + 1);
    }
}

int main(int argc, char *argv[])
{
    char str[] = "AnrbyCTxZVGaKQzbTrTcxAODRsXEfPDfRSQNkqkAoVtNKYcZHeIPfFiaeiYeMTZeNIwQqHPDoDRFfCJC";
    cout << Due((char *)str) << endl;
    cout << str << endl;
    return 0;
}