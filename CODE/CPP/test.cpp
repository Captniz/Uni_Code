using namespace std;

#include <iostream>
#include <string>
#include <stack>
#include "Snippets/Snippets.hpp"

int main()
{
    stc::Queue_Stc<int> list = stc::Queue_Stc<int>();
    list.Enqueue(2);
    cout << "A:" << list.Find(1) << endl;
    list.Print();
}
