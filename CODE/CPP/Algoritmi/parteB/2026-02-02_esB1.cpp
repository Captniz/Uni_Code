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
#include <queue>

const int NODES = 6;
const int K = 15000;
const int HOME = 0;

using namespace std;

class nodo
{
public:
    int index;
    int visited = 0;

    nodo(int i)
    {
        index = i;
    }
};

class grafo
{
public:
    int **adiacenza;
    vector<nodo *> nodi;
};

void print_vec(queue<nodo *> cammino)
{
    while (!cammino.empty())
    {
        cout << cammino.front()->index << " ";
        cammino.pop();
    }
}

void pp_h(grafo *g, nodo *target, int k, queue<nodo *> cammino, int k_tot)
{
    cammino.push(target);
    target->visited = 1;

    for (nodo *n : g->nodi)
    {
        if (g->adiacenza[target->index][n->index] == -1)
            continue;
        if (k_tot + g->adiacenza[target->index][n->index] > (k + 500))
            continue;
        if (n->index == HOME)
        {
            if (k_tot + g->adiacenza[target->index][n->index] < (k - 500))
                continue;
            print_vec(cammino);
            cout << HOME << endl;
            continue;
        }
        if (n->visited == 1)
            continue;

        pp_h(g, n, k, cammino, k_tot + g->adiacenza[target->index][n->index]);
    }

    target->visited = 0;
    return;
}

void pp(grafo *g, nodo *s, int k)
{
    queue<nodo *> cammino;

    pp_h(g, s, k, cammino, 0);
}

int main(int argc, char const *argv[])
{
    freopen("input", "r", stdin);
    grafo *g = new grafo();

    g->adiacenza = new int *[NODES];

    for (int i = 0; i < NODES; i++)
        g->adiacenza[i] = new int[NODES];

    for (int i = 0; i < NODES; i++)
        for (int j = 0; j < NODES; j++)
            cin >> g->adiacenza[i][j];

    for (int i = 0; i < NODES; i++)
        g->nodi.push_back(new nodo(i));

    pp(g, g->nodi[HOME], K);
    return 0;
}
