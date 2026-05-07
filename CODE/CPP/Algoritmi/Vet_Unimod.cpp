#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int unimod(vector<int> *v, int start, int end)
{
    if (start == end)
        return v->at(start);

    int half = (start + ((end - start) / 2));
    int val = v->at(half);

    //! NON FUNZIONA CON SEQUENZE <= 2 ELEMENTI o CON MINIMI AGLI ESTREMI
    if (val > v->at(half + 1))
        return unimod(v, half + 1, end);
    else if (val > v->at(half - 1))
        return unimod(v, start, half);
    else
        return val;
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
    cout << unimod(v, 0, (N - 1));

    return 0;
}
