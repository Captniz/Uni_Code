#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int Nr = 5;
int Ng = 5;

/*A mia figlia (prima elementare) è stato chiesto di disegnare tutte le
possibili sequenze composte da tre pallini rossi e due pallini gialli.
1 Scrivere un algoritmo che stampa tutte le possibili stringhe
composte da nr caratteri R e da ng caratteri G, per un totale di
nr + ng caratteri.
2 Scrivere un algoritmo che conta tutte queste possibili stringhe –
ovviamente senza generarle tutte e poi contandole.
3 Calcolare la complessità computazionale degli algoritmi proposti. */

void stampaComb(vector<bool> comb)
{
    int size = comb.size();
    for (int i = 0; i < size; i++)
        cout << comb[i] ? "red" : "yellow";

    cout << endl;
}


void generaComb(int nr, int ng, vector<bool> comb)
{
    if ((nr + ng) == 0)
    {
        stampaComb(comb);
        return;
    }

    if (nr > 0)
        if (ng == 0)
        {
            for (int i = 0; i < nr; i++)
                comb.push_back(true);

            stampaComb(comb);
            return;
        }
        else
        {
            comb.push_back(true);
            generaComb((nr - 1), ng, comb);
            comb.pop_back();
        }

    if (ng > 0)
        if (nr == 0)
        {
            for (int i = 0; i < ng; i++)
                comb.push_back(false);
            
            stampaComb(comb);
            return;
        }
        else
        {
            comb.push_back(false);
            generaComb(nr, (ng - 1), comb);
            comb.pop_back();
        }

    return;
}

int main()
{
    vector<bool> empt;
    generaComb(Nr, Ng, empt);
    return 0;
}