using namespace std;

#include <iostream>
#include <string>
#include <stack>

int main()
{
    int a = 100;
    char b;
    while (!cin.fail())
    {
        cout << a << endl;
        cin >> a;
    }

    cout << "End of input" << endl;
    return 0;
}
