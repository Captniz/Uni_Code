#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int punto_fisso(vector<int> *v, int start, int end)
{
    if (start == end)
        if (v->at(start) == start)
            return start;
        else
            return -1;

    int half = (start + ((end - start) / 2));

    if (v->at(half) == half)
        return half;
    else if (v->at(half) < half)
        return punto_fisso(v, half + 1, end);
    else
        return punto_fisso(v, start, half);
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
    cout << punto_fisso(v, 0, (N - 1));

    return 0;
}
