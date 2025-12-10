#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("./ricostruzione-albero/input/input.txt");
ofstream out("output.txt");

class TreeNode
{
public:
    int childs;
    int first;
    int second;
};

int N;
vector<int> in_ordine;
vector<int> pre_ordine;
vector<int> post_ordine;
vector<TreeNode> tree;

void input_visita()
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
            in >> pre_ordine[i];
    else
        for (int i = 0; i < N; i++)
            in >> post_ordine[i];

    return;
}

int rebuild_tree_pre(int IND_PRE_Root = 0, int limite_LEFT = 0, int limite_RIGHT = N)
{
    int IND_PRE_Next = IND_PRE_Root + 1;
    int IND_ORD_Root = in_ordine[pre_ordine[IND_PRE_Root]];

    if (IND_PRE_Root >= N - 1) // Se sono finiti i nodi nella visita preordine
        return IND_PRE_Root;   // Ritorno la posizione attuale

    int IND_ORD_Next = in_ordine[pre_ordine[IND_PRE_Next]]; // Nodo SUPPOSTO di sinistra

    if (IND_ORD_Next < IND_ORD_Root) // Se è a sinistra
    {
        tree[pre_ordine[IND_PRE_Root]].first = pre_ordine[IND_PRE_Next];          // Aggiungo il nodo di sinistra al tree (nel nodo radice)
        tree[pre_ordine[IND_PRE_Root]].childs++;                                  // Incremento il numero di figli del nodo radice
        IND_PRE_Next = rebuild_tree_pre(IND_PRE_Next, limite_LEFT, IND_ORD_Root); // Ricostruisco il sottoalbero di sinistra e ottengo il prossimo nodo
        IND_ORD_Next = in_ordine[pre_ordine[IND_PRE_Next]];                       // Aggiorno con il nodo di DESTRA ottenuto da prima
    }

    if (IND_ORD_Next < limite_LEFT || IND_ORD_Next > limite_RIGHT) // Se è a destra ma esce dallo scope ( limite del sottoalbero )
        return IND_PRE_Next;                                       // Ritorna perchè deve essere gestito dal chiamante

    tree[pre_ordine[IND_PRE_Root]].second = pre_ordine[IND_PRE_Next];          // Aggiungo il nodo di destra al tree (nel nodo radice)
    tree[pre_ordine[IND_PRE_Root]].childs++;                                   // Incremento il numero di figli del nodo radice
    IND_PRE_Next = rebuild_tree_pre(IND_PRE_Next, IND_ORD_Root, limite_RIGHT); // Ricostruisco il sottoalbero di destra e ottengo

    return IND_PRE_Next;
}

int rebuild_tree_post(int IND_POST_Root = N-1, int limite_LEFT = 0, int limite_RIGHT = N)
{
    if(N == 0)
        return -1;
    
    
    


    return 0;
}

void print_tree_out()
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

int main()
{
    in >> N;

    in_ordine = vector<int>(N);
    pre_ordine = vector<int>(N);
    post_ordine = vector<int>(N);
    tree = vector<TreeNode>(N, {0, -1, -1});
    
    input_visita();
    input_visita();



    rebuild_tree_post();

    print_tree_out();

    in.close();
    out.close();
    return 0;
}