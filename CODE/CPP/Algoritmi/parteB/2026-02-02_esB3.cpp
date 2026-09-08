/* Sia data una stringa s di n caratteri. Scrivere un algoritmo che stampa una sottostringa (contigua) palindroma
massimale contenuta all’interno di s. Ricordiamo che una stringa palindroma si legge allo stesso modo da sinistra a
destra e da destra a sinistra. Per massimale, si intende che non esistono sottostringhe palindrome più lunghe (ma
possono esisterne altre della stessa lunghezza).
Discutere informalmente la correttezza della soluzione proposta e calcolare la complessità computazionale. Determi-
nare la lunghezza della stringa palindroma massimale e non essere in grado di stamparla dà origine ad un punteggio
inferiore, ma non nullo.
Ad esempio, la stringa casacca contiene le seguenti stringhe palindrome (in ordine crescente di lunghezza): c, a, s,
a, c, c, a, cc, asa, acca, casac. Quindi l’unica stringa da stampare è casac. */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N_CASE = 5;
const int N_COLORI = 3;

int hateville(int mat_costi[N_CASE][N_COLORI])
{
    int DP[N_CASE][N_COLORI];

    for (int i = 0; i < N_COLORI; i++)
        DP[0][i] = mat_costi[0][i];

    for (int i = 1; i < N_CASE; i++)
        for (int j = 0; j < N_COLORI; j++)
            for (int k = 0; k < N_COLORI; k++)
                if (k != j)
                    DP[i][j] = min(DP[i][j], DP[i - 1][k] + mat_costi[i][j]);

    int min_cost = DP[N_CASE - 1][0];
    for (int i = 1; i < N_COLORI; i++)
        min_cost = min(min_cost, DP[N_CASE - 1][i]);

    return min_cost;
}

int main(int argc, char const *argv[])
{
    int mat_costi[N_CASE][N_COLORI] = {{10, 21, 5},
                                       {20, 22, 8},
                                       {30, 13, 15},
                                       {40, 8, 10},
                                       {50, 9, 12}};
    hateville(mat_costi);
    return 0;
}
