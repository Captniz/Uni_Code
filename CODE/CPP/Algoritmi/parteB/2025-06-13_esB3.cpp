#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define K 3
#define N 5

using namespace std;

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

void pt_lesser(int A[], int target, vector<int> s = {})
{
    for (int i = target + 1; i < N; i++)
        if (A[i] < s.back())
        {
            s.push_back(A[i]);
            print_vector(s);
            if (s.size() < K)
                pt_lesser(A, i, s);
            s.pop_back();
        }
}

void pt_higher(int A[], int target, vector<int> s = {})
{
    for (int i = target + 1; i < N; i++)
        if (A[i] > s.back())
        {
            s.push_back(A[i]);
            print_vector(s);
            if (s.size() < K)
                pt_higher(A, i, s);
            s.pop_back();
        }
}

void printTuples(int A[])
{
    for (int i = 0; i < N - 1; i++)
    {
        vector<int> s = {A[i]};
        pt_lesser(A, i, s);
        pt_higher(A, i, s);
    }
}

int main(int argc, char const *argv[])
{
    freopen("input", "r", stdin);

    int A[] = {2, 5, 3, 4, 1};

    printTuples(A);

    return 0;
}
