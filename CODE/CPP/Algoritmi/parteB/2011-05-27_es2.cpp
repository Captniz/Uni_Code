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

string minParentesis(string s)
{
    int i = 0;
    s.insert(0, "(");

    do
    {
        char currchar = s.at(i);
        if (currchar != '*' && currchar != '+')
        {
            i++;
            continue;
        }

        if (currchar == '+')
        {
            s.insert(i, ")");
            s.insert(i + 2, "(");
            i++;
        }
        i++;
    } while (i < s.length());

    s.insert(s.length(), ")");
    return s;
}

int main(int argc, char const *argv[])
{
    string s = "6*5+13*2*3+1+6";
    cout << minParentesis(s) << endl;

    return 0;
}
