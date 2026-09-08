#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 5

int pathsRec(bool A[N][N], int target_x, int target_y, vector<string> path)
{
    if (target_x == 0 && target_y == 0)
    {
        cout << "[";
        for (string p : path)
            cout << " " << p;
        cout << " 0,0 ]\n\n";
        return 1;
    }

    path.push_back(to_string(target_y) + "," + to_string(target_x));

    if (target_x != 0 && A[target_x - 1][target_y] != 0)
        pathsRec(A, target_x - 1, target_y, path);
    if (target_y != 0 && A[target_x][target_y - 1] != 0)
        pathsRec(A, target_x, target_y - 1, path);

    return 0;
}

int main(int argc, char const *argv[])
{
    bool A[N][N] = {
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1}};

    pathsRec(A, N - 1, N - 1, vector<string>());

    return 0;
}
