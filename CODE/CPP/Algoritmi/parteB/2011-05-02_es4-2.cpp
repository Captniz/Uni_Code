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

int longestPal(string s)
{
    int l = s.length();
    int max = 1;
    int currlen = 1;

    for (int i = 0; i < l; i++)
    {
        char currchar = s.at(i);

        if (currlen >= 2)
            if (i - currlen - 1 >= 0 && currchar == s.at(i - currlen - 1))
            {
                currlen += 2;
                if (currlen > max)
                    max = currlen;

                continue;
            }
        if (i - 2 >= 0 && currchar == s.at(i - 2))
            currlen = 3;
        else if (i - 1 >= 0 && currchar == s.at(i - 1))
            currlen = 2;

        if (currlen > max)
            max = currlen;
    }

    return max;
}

int main(int argc, char const *argv[])
{
    string s = "xaaczy";
    cout << longestPal(s) << endl;

    return 0;
}
