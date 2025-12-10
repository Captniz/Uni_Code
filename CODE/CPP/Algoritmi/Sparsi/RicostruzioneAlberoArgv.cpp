#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int childs;
    int first;
    int second;
};

int N;
vector<int> in_ordine;
vector<int> ordine_base;
vector<TreeNode> tree;

int input_visita(ifstream &in)
{
    int type;

    in >> type;

    if (type == 0)
        //? In_ordine non tiene la reale visita in ordine ma invece le posizione dei vari nodi nella visita
        for (int i = 0; i < N; i++)
        {
            int tmp;
            in >> tmp;
            in_ordine[tmp] = i;
        }
    else if (type == -1)
        for (int i = 0; i < N; i++)
            in >> ordine_base[i];
    else
        for (int i = (N - 1); i >= 0; i--)
            in >> ordine_base[i]; //? In post ordine viene invertito l'array per comodità

    return type;
}

int rebuild_tree_pre(int IND_PRE_Root = 0, int limite_LEFT = 0, int limite_RIGHT = N)
{
    int IND_PRE_Next = IND_PRE_Root + 1;
    int IND_ORD_Root = in_ordine[ordine_base[IND_PRE_Root]];

    if (IND_PRE_Root >= N - 1) // Se sono finiti i nodi nella visita preordine
        return IND_PRE_Root;   // Ritorno la posizione attuale

    int IND_ORD_Next = in_ordine[ordine_base[IND_PRE_Next]]; // Nodo SUPPOSTO di sinistra

    if (IND_ORD_Next < IND_ORD_Root) // Se è a sinistra
    {
        tree[ordine_base[IND_PRE_Root]].first = ordine_base[IND_PRE_Next];        // Aggiungo il nodo di sinistra al tree (nel nodo radice)
        tree[ordine_base[IND_PRE_Root]].childs++;                                 // Incremento il numero di figli del nodo radice
        IND_PRE_Next = rebuild_tree_pre(IND_PRE_Next, limite_LEFT, IND_ORD_Root); // Ricostruisco il sottoalbero di sinistra e ottengo il prossimo nodo
        IND_ORD_Next = in_ordine[ordine_base[IND_PRE_Next]];                      // Aggiorno con il nodo di DESTRA ottenuto da prima
    }

    if (IND_ORD_Next < limite_LEFT || IND_ORD_Next > limite_RIGHT) // Se è a destra ma esce dallo scope ( limite del sottoalbero )
        return IND_PRE_Next;                                       // Ritorna perchè deve essere gestito dal chiamante

    if (IND_ORD_Next > IND_ORD_Root) // Se è a destra
    {
        tree[ordine_base[IND_PRE_Root]].second = ordine_base[IND_PRE_Next];        // Aggiungo il nodo di destra al tree (nel nodo radice)
        tree[ordine_base[IND_PRE_Root]].childs++;                                  // Incremento il numero di figli del nodo radice
        IND_PRE_Next = rebuild_tree_pre(IND_PRE_Next, IND_ORD_Root, limite_RIGHT); // Ricostruisco il sottoalbero di destra e ottengo
    }
    return IND_PRE_Next;
}

int rebuild_tree_post(int IND_POST_Root = 0, int limite_LEFT = 0, int limite_RIGHT = N)
{
    int IND_POST_Next = IND_POST_Root + 1;
    int IND_ORD_Root = in_ordine[ordine_base[IND_POST_Root]];

    if (IND_POST_Root >= N - 1) // Se sono finiti i nodi nella visita preordine
        return IND_POST_Root;   // Ritorno la posizione attuale

    int IND_ORD_Next = in_ordine[ordine_base[IND_POST_Next]]; // Nodo SUPPOSTO di destra

    if (IND_ORD_Next > IND_ORD_Root) // Se è a destra
    {
        tree[ordine_base[IND_POST_Root]].second = ordine_base[IND_POST_Next];         // Aggiungo il nodo di destra al tree (nel nodo radice)
        tree[ordine_base[IND_POST_Root]].childs++;                                    // Incremento il numero di figli del nodo radice
        IND_POST_Next = rebuild_tree_post(IND_POST_Next, IND_ORD_Root, limite_RIGHT); // Ricostruisco il sottoalbero di destra e ottengo il prossimo nodo
        IND_ORD_Next = in_ordine[ordine_base[IND_POST_Next]];                         // Aggiorno con il nodo di SINISTRA ottenuto da prima
    }

    if (IND_ORD_Next < limite_LEFT || IND_ORD_Next > limite_RIGHT) // Se è a sinistra ma esce dallo scope ( limite del sottoalbero )
        return IND_POST_Next;                                      // Ritorna perchè deve essere gestito dal chiamante

    if (IND_ORD_Next < IND_ORD_Root) // Se è a destra
    {
        tree[ordine_base[IND_POST_Root]].first = ordine_base[IND_POST_Next];         // Aggiungo il nodo di sinistra al tree (nel nodo radice)
        tree[ordine_base[IND_POST_Root]].childs++;                                   // Incremento il numero di figli del nodo radice
        IND_POST_Next = rebuild_tree_post(IND_POST_Next, limite_LEFT, IND_ORD_Root); // Ricostruisco il sottoalbero di sinistra e ottengo
    }
    return IND_POST_Next;
}

void print_tree_out(ofstream &out)
{
    for (int i = 0; i < N; i++)
    {
        out << i << " " << tree[i].childs;
        if (tree[i].first != -1)
            out << " " << tree[i].first;
        if (tree[i].second != -1)
            out << " " << tree[i].second;
        out << "\n";
    }
}

int main(int argc, char *argv[])
{
    // if argv are provided, use them for input and output files
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (argc == 3)
    {
        ifstream inFile(argv[1]);
        ofstream outFile(argv[2]);
        in.swap(inFile);
        out.swap(outFile);
    }
    if (argc == 2)
    {
        ifstream inFile(argv[1]);
        in.swap(inFile);
    }

    in >> N;

    in_ordine = vector<int>(N);
    ordine_base = vector<int>(N);
    tree = vector<TreeNode>(N, {0, -1, -1});

    int type = 0;
    type += input_visita(in);
    type += input_visita(in);

    if (type == -1)
        rebuild_tree_pre();
    else
        rebuild_tree_post();

    print_tree_out(out);

    in.close();
    out.close();
    return 0;
}