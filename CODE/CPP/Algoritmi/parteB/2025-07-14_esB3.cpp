#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define N 4

using namespace std;

void print_vector(vector<string> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void printAllPaths(int M[N][N], int visited[N][N], const int max_trav, int i_target, int j_target, int traversed = 0, vector<string> path = {})
{
    path.push_back("(" + to_string(i_target) + ", " + to_string(j_target) + ")");
    if (M[i_target][j_target] == 2)
        if (traversed == max_trav)
            print_vector(path);
        else
            return;

    traversed++;
    visited[i_target][j_target] = 1;

    if ((i_target - 1) >= 0)
        if (visited[(i_target - 1)][j_target] == 0 && M[(i_target - 1)][j_target] != -1)
            printAllPaths(M, visited, max_trav, (i_target - 1), j_target, traversed, path);
    if ((i_target + 1) < N)
        if (visited[(i_target + 1)][j_target] == 0 && M[(i_target + 1)][j_target] != -1)
            printAllPaths(M, visited, max_trav, (i_target + 1), j_target, traversed, path);
    if ((j_target - 1) >= 0)
        if (visited[i_target][(j_target - 1)] == 0 && M[i_target][(j_target - 1)] != -1)
            printAllPaths(M, visited, max_trav, i_target, (j_target - 1), traversed, path);
    if ((j_target + 1) < N)
        if (visited[i_target][(j_target + 1)] == 0 && M[i_target][(j_target + 1)] != -1)
            printAllPaths(M, visited, max_trav, i_target, (j_target + 1), traversed, path);

    visited[i_target][j_target] = 0;
    traversed--;
    return;
}

int main(int argc, char const *argv[])
{
    freopen("input", "r", stdin);

    int M[N][N];
    int visited[N][N] = {0};
    int traversable_count = 0;
    int i_target, j_target;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> M[i][j];
            if (M[i][j] == 0)
                traversable_count++;
            if (M[i][j] == 1)
            {
                traversable_count++;
                i_target = i;
                j_target = j;
            }
        }

    printAllPaths(M, visited, traversable_count, i_target, j_target);
    return 0;
}
