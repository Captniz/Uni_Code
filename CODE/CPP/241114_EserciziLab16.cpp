using namespace std;

#include <iostream>
#include <fstream>
#include "Snippets/Snippets.hpp"

void Uno(int n)
{
    arr::Print_Arr(arr::Random_Arr(n, 0, 99), n);
}

void Due(int r, int c)
{
    mat::Print_Mat(mat::Random_Mat(r, c, 0, 99), r, c);
}

void Tre(int argc, char const *argv[])
{
    fstream in;

    int len = atoi(argv[2]);
    in = fstream(argv[1], ios::in);
    float *temp = new float[len];

    if (in.is_open())
    {
        cout << "Errore nell'apertura del file." << endl;
        return;
    }

    for (int i = 0; i < len; i++)
    {
        char *tmp = new char[100];
        in >> tmp;
        temp[i] = atof(tmp);
    }

    arr::Sort_Arr(temp, len);

    for (int i = 0; i < atoi(argv[3]); i++)
    {
        cout << temp[len - 1 - i] << " ";
    }

    in.close();
}

int main(int argc, char const *argv[])
{
    Tre(argc, argv);
    return 0;
}
