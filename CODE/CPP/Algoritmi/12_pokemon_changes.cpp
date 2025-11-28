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

class Node
{
public:
    Link *link;
    Node *parent;

    Node(Link *val)
    {
        link = val;
        parent = nullptr;
    }

    Node(Link *val, Node *par)
    {
        link = val;
        parent = par;
    }

    ~Node()
    {
        delete parent;
    }
};

vector<Node *> cycles;

void printCycles()
{
    cout << "Found " << cycles.size() << " cycles:" << endl;

    for (Node *cycle : cycles)
    {
        Node *current = cycle;
        while (current != nullptr)
        {
            cout << current->link->value << " ";
            current = current->parent;
        }
        cout << endl;
    }
}

int getShortestCycleLinks()
{
    int min_length = N + 1;

    for (Node *cycle : cycles)
    {
        int length = 3;                            // Min cycle length is 3
        Node *current = cycle;                     // Start from the cycle root node
        int root_value = cycle->link->value;       // Store the root value to identify the cycle completion
        current = current->parent->parent->parent; // Move to the 4th node in the cycle, so we avoid checking the forced nodes (0->1->2->0, 0:root,1/2 are forced for it to be a cycle, check from the 4th so 0)
        while (current->link->value != root_value)
        {
            length++;
            current = current->parent;
        }
        if (length < min_length)
            if (length == 3)
                return 4;
            else
                min_length = length;
    }

    return min_length; // +1 to convert links to nodes
}

Node *find_cycle(vector<Link *> *links, Link *curr, Link *prev)
{
    Node *curr_node = new Node(curr);

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
                ret->parent = curr_node;            // Aggiungi al nodo corrente il risultato della chiamata ricorsiva
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
            find_cycle(links, i, links->at(origin))->parent = new Node(links->at(origin));
}

void find_all_cycles(vector<Link *> *links)
{
    for (int i = 0; i < N; i++)
        if (!links->at(i)->visited && links->at(i)->linked_nodes.size() > 1)
            origin_find_cycles(links, i);
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

    find_all_cycles(&links);

    // printCycles();

    if (cycles.empty())
    {
        out << 0 << endl;

        // Clean up
        in.close();
        out.close();
        links.clear();

        return 0;
    }

    // cout << "Shortest cycle links number: " << getShortestCycleLinks() << endl;
    out << getShortestCycleLinks() << endl;

    // Clean up
    in.close();
    out.close();
    links.clear();

    return 0;
}