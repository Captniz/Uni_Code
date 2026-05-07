#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool SubsetSum(vector<int> set, int sum)
{
    int set_len = set.size();
    vector<int> DP;

    DP[0] = set[0] <= sum ? set[0] : 0;

    for (int i = 0; i < set_len; i++)
    {
        if (DP[i - 1] == sum)
            return true;

        DP[i] =
    }
}

int main()
{
    return 0;
}