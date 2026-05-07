#include <iostream>

using namespace std;

int value(int *seg)
{
    return seg[1] - seg[0];
}

int copertura(int **seg, int n)
{
    int Prev[n];
    for (int i = 0; i < n; i++)
    {
        Prev[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if (seg[j][1] <= seg[i][0])
                Prev[i] = j;
        }
    }
    
    int DP[n];
    DP[0] = 0;

    for (int i = 1; i < n; i++)
    {
        DP[i] = max(DP[i - 1], value(seg[n - i]) + (Prev[n - i] != -1 ? DP[Prev[n - i]] : 0));
    }

    return DP[n - 1];
}

int main(int argc, char const *argv[])
{
    int n = 5;
    int **segmenti = new int *[n];

    int s[5] = {0, 1, 5, 6, 10};
    int f[5] = {4, 5, 14, 9, 13};

    for (int i = 0; i < n; i++)
    {
        segmenti[i] = new int[2];
        segmenti[i][0] = s[i];
        segmenti[i][1] = f[i];
    }

    cout << copertura(segmenti, n) << endl;

    return 0;
}
