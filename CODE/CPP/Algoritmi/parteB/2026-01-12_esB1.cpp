#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int N = 5;
const int max_ones = (N + 1) / 2 - 1;

void printVector(vector<int> arr)
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

void printZerable(int start, vector<int> arr, int current_ones)
{
    for (int i = start; i < N; i++)
    {
        arr[i] = 1;
        printVector(arr);
        if (current_ones < max_ones)
            printZerable(i + 1, arr, current_ones + 1);
        arr[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr(N, 0);
    printZerable(0, arr, 1);
}
