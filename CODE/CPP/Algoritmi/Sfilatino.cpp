#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L = 100;
int N = 10;

void _print_vector(vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int sfilatino(vector<int> richieste)
{
    int l = L;
    int served = 0;
    sort(richieste.begin(), richieste.end());
    //i_print_vector(richieste);

    for (;;)
    {
        l -= richieste[served];
        if (l < 0)
            return served;
        served++;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> richieste = {10, 12, 5, 20, 15, 30, 25, 8, 18, 22};

    cout << endl
         << sfilatino(richieste) << endl;

    return 0;
}
