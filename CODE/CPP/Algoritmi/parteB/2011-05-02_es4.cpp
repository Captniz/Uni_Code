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

using namespace std;

void prevPal(string s, int start, int end, int **DP, int *max)
{
    if (start == end)
    {
        DP[start][end] = 1;
        return;
    }

    for (int i = start; i <= end; i++)
        for (int j = start; j <= end; j++)
        {
            int prev_pal;
            if (i + 1 < j - 1)
            {
                if (DP[i + 1][j - 1] == -1)
                    prevPal(s, i + 1, j - 1, DP, max);

                prev_pal = DP[i + 1][j - 1];

                if (prev_pal != 0 && s[i] == s[j])
                    DP[i][j] = prev_pal + 2;
                else
                    DP[i][j] = 0;
            }
            else if (s[i] == s[j])
                DP[i][j] = 2;
            else
                DP[i][j] = 0;

            if (DP[i][j] > *max)
                *max = DP[i][j];
        }
}

int main(int argc, char const *argv[])
{
    string s = "caccac";
    int s_len = s.length();
    int **DP = new int *[s_len];

    for (int i = 0; i < s_len; i++)
        DP[i] = new int[s_len];

    for (int i = 0; i < s_len; i++)
        for (int j = 0; j < s_len; j++)
            DP[i][j] = -1;

    int max = 0;
    prevPal(s, 0, s_len - 1, DP, &max);

    cout << max << endl
         << endl;

    for (int i = 0; i < s_len; i++)
    {
        for (int j = 0; j < s_len; j++)
            cout << DP[i][j] << " ";
        cout << endl;
    }

    return 0;
}
