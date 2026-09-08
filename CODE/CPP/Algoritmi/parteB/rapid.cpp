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

using namespace std;

void printvector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void countArithmetic(vector<int> A, int n)
{
    int i = 0;
    while (i < n - 2)
    {
        int diff = A[i + 1] - A[i];

        if (A[i + 2] != (A[i + 1] + diff))
        {
            i++;
            continue;
        }

        int j = i + 3;
        vector<int> seq;
        seq.push_back(A[i]);
        seq.push_back(A[i + 1]);
        seq.push_back(A[i + 2]);

        while (j < n && A[j] == A[j - 1] + diff)
        {
            seq.push_back(A[j]);
            j++;
        }

        printvector(seq);
        i = j - 1;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {-1, 1, 3, 5, 8, 11};
    countArithmetic(vec, vec.size());

    return 0;
}
