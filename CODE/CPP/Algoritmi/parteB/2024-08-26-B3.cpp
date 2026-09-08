#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define SIZE 5

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

void zigzag(int A[], vector<int> seq, int target)
{
    print_vector(seq);
    bool even = (seq.size() % 2 != 0);

    if (even)
    {
        for (int i = target; i < SIZE; i++)
            if (A[i] > seq.back())
            {
                vector<int> new_seq = seq;
                new_seq.push_back(A[i]);
                zigzag(A, new_seq, i + 1);
            }
    }
    else
    {

        for (int i = target; i < SIZE; i++)
            if (A[i] < seq.back())
            {
                vector<int> new_seq = seq;
                new_seq.push_back(A[i]);
                zigzag(A, new_seq, i + 1);
            }
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {1, 3, 6, 4, 5};

    cout << "[]" << endl;
    for (int i = 0; i < SIZE; i++)
        zigzag(A, {A[i]}, i);
    return 0;
}
