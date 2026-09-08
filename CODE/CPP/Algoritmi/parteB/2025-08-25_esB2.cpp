#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define K 2
#define SIZE 5

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

void pp(int A[], vector<int> s, int target)
{
    s.push_back(A[target]);

    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j < s.size(); j++)
            if (abs(s[i] - s[j]) <= K)
                return;

    print_vector(s);

    for (int i = target + 1; i < SIZE; i++)
        pp(A, s, i);
}

int main(int argc, char const *argv[])
{
    int A[] = {2, 4, -2, 5, 2};

    cout << "vuoto, " << endl;

    vector<int> s;
    for (int i = 0; i < SIZE; i++)
        pp(A, s, i);

    return 0;
}
