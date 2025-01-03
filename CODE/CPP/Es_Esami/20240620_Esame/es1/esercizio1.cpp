// Allowed include
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

// Add your code hereafter

using namespace std;

int main(int argc, char const *argv[])
{
    fstream in = fstream("./input.txt", ios::in);
    fstream out = fstream("output.txt", ios::out);
    char **text = new char *[100];

    if (!in.is_open())
    {
        cout << "Errore nell'apertura del file di input" << endl;
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
        out << text[j] << endl;
    }

    return 0;
}
