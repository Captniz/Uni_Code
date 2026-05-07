#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N;

void printVec(vector<int> v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
        cout << v[i];

    cout << endl;
    return;
}

void generaCombinazioni(int prev_i, int n, vector<int> comb)
{
    if (n == 0)
    {
        printVec(comb);
        return;
    }

    int i = prev_i;
    while ((n - (i * i)) >= 0)
    {
        comb.push_back(i);
        generaCombinazioni(i, n - (i * i), comb);
        comb.pop_back();
        i++;
    }
    return;
}

int main()
{
    vector<int> empt;
    generaCombinazioni(1, 1892471, empt);
    return 0;
}