
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
    int *arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    cout << arr << endl;
    cout << &arr[0] << endl;

    cout << arr + 1 << endl;
    cout << &arr[1] << endl;
}
