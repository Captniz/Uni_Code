#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N; // Num Nodi
int R; // Num Archi

/*
La dist è sicuramente <= R
*/

int find_distance(vector<vector<int>> grafo,)
{
    
}

int main()
{
    in >> N >> R;

    vector<vector<int>> grafo(N);

    for (int i = 0; i < R; i++)
    {
        int u, v;
        in >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    in.close();
    out.close();
    return 0;
}