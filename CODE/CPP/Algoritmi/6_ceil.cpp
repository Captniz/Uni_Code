#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int V_n;
int A_n;

/**
 * @brief Prende in input un x detto Floor e
    restituisce l'indice dell'intervallo con il ceil maggiore di x meno distante.
 *
 * @param search_array list of all numbers
 * @param x floor
 * @param start start index of the search
 * @param end end index of the search
 * @return found number
 */
int get_next_ceil_to_floor(vector<int> *search_arr, int x, int start, int end)
{
    if (start == end)
        if (x >= search_arr->at(start))
            return search_arr->at(start + 1);
        else
            return search_arr->at(start);

    int half = (start + ((end - start) / 2));
    int dicotomic_find = search_arr->at(half);

    if (dicotomic_find == x)
        return search_arr->at(half + 1);
    else if (dicotomic_find < x)
        return get_next_ceil_to_floor(search_arr, x, half + 1, end);
    else
        return get_next_ceil_to_floor(search_arr, x, start, half);
}

int main(int argc, char const *argv[])
{
    ifstream in("input.txt");
    in >> V_n;
    in >> A_n;

    vector<int> *targets = new vector<int>(V_n);
    for (int i = 0; i < V_n; i++)
        in >> targets->at(i);

    vector<int> *search_array = new vector<int>();
    int prev = 0;
    int curr = 0;
    in >> prev;
    search_array->push_back(prev);

    for (int i = 0; i < A_n - 1; i++)
    {
        in >> curr;
        if (curr == prev)
            continue;
        search_array->push_back(curr);
        prev = curr;
    }
    in.close();

    ofstream out("output.txt");

    int max = search_array->at(search_array->size() - 1);

    for (int i = 0; i < V_n; i++)
    {
        if (targets->at(i) >= max)
        {
            out << -1 << " ";
            continue;
        }
        out << get_next_ceil_to_floor(search_array, targets->at(i), 0, search_array->size() - 1) << " ";
    }

    return 0;
}
