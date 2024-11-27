
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
    char **str = new char *[3];
    str[0] = new char[256];
    str[1] = new char[256];
    str[2] = new char[256];

    cin >> str[0];
    cin >> str[1];
    cin >> str[2];

    Sort_Arr(str, 3);
    char **res = Copy_Arr(str, 3);
    Print_Arr(res, 3);

    Stack_Stc<char *> stack = Stack_Stc<char *>(str, 3);
    stack.Print();
}
