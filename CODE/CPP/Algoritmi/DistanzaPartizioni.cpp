#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
Dato un grafo G e due sottoinsiemi V1 e V2 dei suoi vertici, si definisce distanza tra V1 e V2 la distanza minima per andare da un nodo in V1 ad un nodo in V2, misurata in numero di archi.
Nel caso V1 e V2 non siano disgiunti, allora la distanza è 0.

Scrivere un algoritmo mindist(Graph G, Set V1, Set V2) che restituisce la distanza minima fra V1 e V2.

Discutere complessità e correttezza, assumendo che l’implementazione degli insiemi sia tale che il costo di verificare l’appartenenza di un elemento all’insieme abbia costo O(1).

Nota: è facile scrivere un algoritmo O(nm); esistono tuttavia algoritmi di complessità O(n^2) (con matrice di adiacenza) e O(m + n). */

ifstream in("input.txt");
ofstream out("output.txt");

int N; // Node count
int M; // Edge count

class Link
{
public:
    int value;
    int V1Dist;
    int group;    // v1 = 1, v2 = 2, none = 0
    bool visited; // Indica se il nodo è stato visitato in precedenza, indipendentemente dal ramo
    vector<Link *> linked_nodes;

    Link()
    {
        value = -1;
        visited = false;
        V1Dist = -1;
        linked_nodes = {};
    }

    Link(int val)
    {
        value = val;
        visited = false;
        V1Dist = -1;
        linked_nodes = {};
    }

    ~Link()
    {
        for (Link *node : linked_nodes)
            delete node;
    }
};

void findV1Dist(Link *link, Link *prev)
{
    int min = N + 1;
    link->visited = true;

    for (Link *linked_node : link->linked_nodes)
        if (linked_node->value != prev->value)
        {
            if (linked_node->V1Dist == -1)
                findV1Dist(linked_node, link);
            min = (min < linked_node->V1Dist ? min : linked_node->V1Dist);
        }

    link->V1Dist = (min + 1);
}

int findDistance(vector<Link *> links)
{
    int min = N + 1;
    for (Link *link : links)
        if (link->group == 2)
        {
            findV1Dist(link, link);
            min = (min < link->V1Dist ? min : link->V1Dist);
        }

    return min == N + 1 ? -1 : min;  // Return -1 if no path found
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

    int v;
    in >> v;
    for (int i = 0; i < v; i++)
    {
        int tmp;
        in >> tmp;
        links.at(tmp)->group = 1;
        links.at(tmp)->V1Dist = 0;
    }

    in >> v;
    for (int i = 0; i < v; i++)
    {
        int tmp;
        in >> tmp;
        links.at(tmp)->group = 2;
    }

    /*     // DEBUG PRINT
        for (Link *link : links)
        {
            cout << "Node " << link->value << " group: " << link->group << " linked to: ";
            for (Link *l : link->linked_nodes)
                cout << l->value << " ";
            cout << endl;
        } */

    cout << findDistance(links);

    in.close();
    out.close();
    return 0;
}