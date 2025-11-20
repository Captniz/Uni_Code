#include <iostream>
#include <fstream>
using namespace std;

int R, C;

int f(int *A)
{
    int max = 0;
    int sum = 0;

    for (int i = 0; i < C; i++)
    {
        sum += A[i];

        if (max < sum)
            max = sum;

        if (sum < 0)
            sum = 0;
    }

    return max;
}

int *sumrows(int **A, int start, int n)
{
    int *sum = new int[C];
    for (int j = 0; j < C; j++)
        sum[j] = 0;

    for (int i = 0; i < C; i++)
        for (int j = start; j < start + n; j++)
            sum[i] += A[j][i];

    return sum;
}


int f2(int **A)
{
    int max = 0;

    for (int i = 0; i < R; i++)
        for (int j = 1; j <= R - i; j++)
        {
            int *sum = sumrows(A, i, j);
            int curr = f(sum);
            if (curr > max)
                max = curr;
            delete[] sum;
        }

    return max;
}

int main()
{
    ifstream in("input.txt");

    in >> R >> C;
    int **A = new int *[R];

    for (int i = 0; i < R; i++)
        A[i] = new int[C];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            in >> A[i][j];

    if (R > C)
    {
        int **B = new int *[C];
        for (int i = 0; i < C; i++)
            B[i] = new int[R];

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                B[j][i] = A[i][j];

        swap(R, C);
        A = B;
    }

    ofstream out("output.txt");
    out << f2(A) << endl;
    return 0;
}
