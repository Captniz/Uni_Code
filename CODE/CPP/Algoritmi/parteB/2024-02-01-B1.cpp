#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define N 7

void print_vector(vector<int> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void lessThanHalf(int n = N, vector<int> seq = {})
{
    seq.push_back(n);
    print_vector(seq);

    int tmp = 1;

    while (tmp * 2 <= n)
    {
        lessThanHalf(tmp, seq);
        tmp++;
    }
}

int main(int argc, char const *argv[])
{
    lessThanHalf();
    return 0;
}
