using namespace std;

#include <iostream>

int main()
{
    int a = 5;
    int *p = &a;
    int *q;

    cout << "&a: " << &a << " | *a: " << "" << " | a:" << a << endl;
    cout << "&p: " << &p << " | *p: " << *p << " | p:" << p << endl;
    cout << "&q: " << &q << " | *q: " << *q << " | q:" << q << endl;
    return 0;
}
