
#include <iostream>
#include <string>
#include <stack>
#include "Snippets/Arrays.hpp"
#include "Snippets/Structures.hpp"

using namespace std;
using namespace arr;
using namespace stc;

int main()
{
    int arr[] = {3, 2, 1, 9, 8, 10, 4, 23, 13, 6, 7, 50, 5, 91, -1, 25,12,11};
    Tree_Stc<int> tree = Tree_Stc<int>(arr, sizeof(arr) / sizeof(arr[0]));

    tree.Print();
    tree.Print_InOrder();
    cout << endl
         << endl;
    tree.Balance();
    cout << endl
         << endl;
    tree.Print();
    cout << endl
         << endl
         << endl;
    tree.Print_LevelOrder();
    cout << "Size: " << tree.Size() << endl;
    cout << "Levels: " << tree.Levels() << endl;
}
/*
int main()
{
    int arr_c[] = {0, 1, 2};
    int **arr = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i] = &arr_c[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cout << *arr[i] << endl;
    }
}*/