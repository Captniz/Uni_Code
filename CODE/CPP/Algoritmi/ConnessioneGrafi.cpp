#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    bool visited = false;

    Node(int v)
    {
        val = v;
        neighbors = {};
    }
};

int N;
int M;

vector<Node *> roots;
vector<Node *> *graph;

void exploreComponent(Node *n)
{
    n->visited = true;
    for (Node *neighbor : n->neighbors)
        if (!neighbor->visited)
            exploreComponent(neighbor);
}

void findComponents()
{
    for (Node *i : *graph)
        if (!i->visited)
        {
            roots.push_back(i);
            exploreComponent(i);
        }
}

int main()
{
    in >> N >> M;

    graph = new vector<Node *>(N);

    for (int i = 0; i < N; i++)
        graph->at(i) = new Node(i);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        in >> a >> b;

        graph->at(a)->neighbors.push_back(graph->at(b));
        graph->at(b)->neighbors.push_back(graph->at(a));
    }

    findComponents();

    for (Node *r : roots)
        cout << r->val << " ";
    cout << "\n";

    in.close();
    out.close();
    return 0;
}