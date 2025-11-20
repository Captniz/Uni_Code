#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
 ? APPUNTI:
 * Il num massimo di pokemon è dato dal ciclo più piccolo. (forse -> caso di un ciclo minore [4 nodi] con un ciclo maggiore non multiplo [6 nodi] = 4 pokemon rompe la 2nda regola / 6 pokemon rompe la 1a regola)

 ?TODO:
 ! Per i link a riga non si formano cicli e quindi ritorna nullptr, questo potrebbe essere semplificato se potessi ignorarli dopo il primo check
 ! Possibilmente inverti i cicli come rappresentazione in modo da poter associare anche una lunghezza/profondità del ciclo per il punto 2
 ! Evita i cicli inversi
 ! Riordina i nodi per la stampa
 ! Conta i nodi in ogni ciclo e trova il minimo
 ! Unisci i nodi dei cicli e il link per risparmiare tempo e spazio
 */

int N; // Node count
int M; // Edge count

ifstream in("input.txt");
ofstream out("output.txt");

class Node
{
public:
    int value;
    vector<Node *> next;

    Node(int val)
    {
        value = val;
        next = {};
    }

    Node(int val, vector<Node *> children)
    {
        value = val;
        next = children;
    }

    Node(int val, Node *child)
    {
        value = val;
        next = {};
        next.push_back(child);
    }

    ~Node()
    {
        for (Node *child : next)
            delete child;
    }
};

class Link
{
public:
    int value;
    bool active;  // Indica se il nodo è parte del ramo di esplorazione corrente
    bool visited; // Indica se il nodo è stato visitato in precedenza, indipendentemente dal ramo
    vector<Link *> linked_nodes;

    Link()
    {
        value = -1;
        active = false;
        visited = false;
        linked_nodes = {};
    }

    Link(int val)
    {
        value = val;
        active = false;
        visited = false;
        linked_nodes = {};
    }

    ~Link()
    {
        for (Link *node : linked_nodes)
            delete node;
    }
};

vector<Node *> cycles;

void printTree(Node *root, const string &prefix = "", bool isLast = true)
{
    if (!root)
        return;

    cout << prefix;

    if (!prefix.empty())
    {
        cout << (isLast ? "└── " : "├── ");
    }

    cout << root->value << endl;

    for (size_t i = 0; i < root->next.size(); i++)
    {
        bool lastChild = (i == root->next.size() - 1);
        printTree(root->next[i],
                  prefix + (isLast ? "    " : "│   "),
                  lastChild);
    }
}

Node *find_cycle(vector<Link *> *links, Link *curr, Link *prev)
{
    Node *curr_node = new Node(curr->value);

    if (curr->active)
    {
        cycles.push_back(curr_node); // Se e' gia' stato visitato esiste un ciclo
        return curr_node;            // Ritorna un nodo con solo valore e 0 figli
    }

    curr->active = true;  // Segna il nodo come attivo nel ramo corrente
    curr->visited = true; // Segna il nodo come visitato per gli altri rami

    for (Link *i : curr->linked_nodes)
    {                                                              // Cicla sui vicini
        if (i->linked_nodes.size() > 1 && prev->value != i->value) // Evita di tornare indietro e evita i nodi foglia
        {
            Node *ret = find_cycle(links, i, curr); // Chiamata ricorsiva
            if (ret != nullptr)                     // Controlla se il risultato non è nullo (Caso di un percorso senza ciclo)
                ret->next.push_back(curr_node);     // Aggiungi al nodo corrente il risultato della chiamata ricorsiva
        }
    }

    curr->active = false; // Segna il nodo come non attivo nel ramo corrente

    return curr_node; // Ritorna il nodo corrente
}

void origin_find_cycles(vector<Link *> *links, int origin)
{
    links->at(origin)->visited = true; // Segna il nodo di origine come visitato
    links->at(origin)->active = true;  // Segna il nodo di origine come attivo

    for (Link *i : links->at(origin)->linked_nodes)
        // Cicla sui vicini
        if (!i->visited && i->linked_nodes.size() > 1)
            // Evita i nodi gia' visitati e i nodi foglia
            find_cycle(links, i, links->at(origin))->next.push_back(new Node{links->at(origin)->value});
}

int main()
{
    in >> N >> M;

    vector<Link *> links(N);

    for (int i = 0; i < N; i++)
        links.at(i) = new Link(i);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        in >> a >> b;

        links.at(a)->linked_nodes.push_back(links.at(b));
        links.at(b)->linked_nodes.push_back(links.at(a));
    }

    origin_find_cycles(&links, 0);

    cout << "Found "<< cycles.size() <<" cycles:" << endl;

    for (Node *cycle : cycles)
        printTree(cycle);

    // Clean up
    /*
        in.close();
        out.close();
        links.clear();
        for (Node *cycle : cycles)
            delete cycle;
        cycles.clear(); */

    return 0;
}