#include <iostream>
#include <vector>
using namespace std;

int dim = 5;
int checkBound(int row, int col, int **dp)
{
    if (col < 0 || col >= dim)
        return 0;
    return dp[row][col];
}

int maxSuperior(int **dp, int row, int col)
{
    return max(checkBound(row - 1, col - 1, dp), max(dp[row - 1][col], checkBound(row - 1, col + 1, dp)));
}

int PathFindScacchi(int **P)
{
    // Inizializzazione di dp
    int **dp = new int *[dim - 1];
    for (int i = 0; i < dim; i++)
        dp[i] = new int[dim];

    // Inizializzo prima riga
    for (int i = 0; i < dim; i++)
        dp[0][i] = P[0][i];

    // Riempimento di dp
    for (int i = 1; i < dim - 1; i++)
        for (int j = 0; j < dim; j++)
            dp[i][j] = P[i][j] + maxSuperior(dp, i, j);

    int max = 0;
    for (int i = 0; i < dim; i++)
    {
        int tmp = P[dim - 1][i] + maxSuperior(dp, dim - 1, i);
        max = max > tmp ? max : tmp;
    }

    return max;
};

int main()
{

    int **P = new int *[dim]{
        new int[dim]{6, 7, 4, 7, 8},
        new int[dim]{7, 6, 1, 1, 4},
        new int[dim]{3, 5, 7, 8, 2},
        new int[dim]{2, 6, 7, 0, 2},
        new int[dim]{7, 3, 5, 6, 1}};

    cout << PathFindScacchi(P) << endl;
    return 0;
}