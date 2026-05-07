#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int sottocres(int N, vector<int> *v)
{

    vector<int> DP = vector<int>((N + 1), 0);

    DP[0] = 0;
    DP[1] = v->at(N - 1);

    for (int i = 1; i < N; i++)
        if (v->at((N - 1) - i) < v->at(N - i))
            DP[i + 1] = DP[i] + v->at(N - 1 - i);
        else if (v->at(N - 1 - i) > DP[(i - 1)])
            DP[i + 1] = v->at(N - 1 - i);
        else
            DP[i + 1] = DP[i];

    return DP[N];
}

int main(int argc, char const *argv[])
{
    int N;

    ifstream in("in.txt");
    ofstream out("out.txt");

    in >> N;
    vector<int> *v = new vector<int>(N);

    for (int i = 0; i < N; i++)
        in >> v->at(i);

    in.close();
    out.close();

    cout << sottocres(N, v);

    return 0;
}

/*
 * Array di numeri:
 * 1. Prendere l'elemento X_i elimina tutti gli elementi che:
 *      - Vengono dopo X_i
 *      - Hanno valore minore di X_i
 *
 * Obiettivo: MASSIMIZZARE LA SOMMA DEI NUMERI
 */
