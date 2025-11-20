#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int chi_manca(vector<int> *v, int start, int end)
{
    if (start == end)
        if (v->at(start) > start)
            return v->at(start) - 1;
        else
            return v->at(start) + 1;

    int half = (start + ((end - start) / 2));

    if (v->at(half) == half)
        return chi_manca(v, half + 1, end);
    else
        return chi_manca(v, start, half);
}

int main(int argc, char const *argv[])
{
    int N = 0;
    ifstream in("input.txt");
    in >> N;

    vector<int> *v = new vector<int>();
    for (int i = 0; i < N; i++)
    {
        int val;
        in >> val;
        v->push_back(val);
    }

    in.close();
    cout << chi_manca(v, 0, (N - 1));

    return 0;
}
