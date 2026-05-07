#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K = 3;
int N = 10;

int max_seg(vector<int> sums)
{
    int max_index = 0;

    for (size_t i = 1; i < K; i++)
        max_index = (sums[max_index] < sums[i] ? i : max_index);

    return max_index;
}

int min_adj(vector<int> sums, int target_index)
{
    // Returns a num that summed to target gets the minor adj sum

    if (target_index == 0)
        return 1;
    else if (target_index == (K - 1))
        return -1;
    else if (sums[target_index - 1] < sums[target_index + 1])
        return -1;
    return 1;
}

void _print_vector(vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int partizione(vector<int> vet)
{
    vector<int> pointers = vector<int>(K, 0);
    vector<int> sums = vector<int>(K, 0);
    int div = N / K;

    for (int i = 0; i < K; i++)
        pointers[i] = i * div;

    int selpoint = 0;
    for (int i = 0; i < N; i++)
    {
        if (selpoint < (K - 1) && i >= pointers[selpoint + 1])
            selpoint++;
        sums[selpoint] += vet[i];
    }

    int global_min_sum = sums[0];
    for (int i = 1; i < K; i++)
        global_min_sum = (global_min_sum < sums[i] ? global_min_sum : sums[i]);

    while (true)
    {
        int current_max_seg = max_seg(sums);
        int min_adj_segment = min_adj(sums, current_max_seg);

        
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vet = {10, 12, 5, 20, 15, 30, 25, 8, 18, 22};

    cout << endl
         << partizione(vet) << endl;

    return 0;
}
