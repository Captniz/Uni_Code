#include <iostream>
using namespace std;

int main()
{
    for (long i = 999; i > 99; i--)
    {
        for (long j = i; j > 99; j--)
        {
            int prod = i * j;

            int a = prod / 100000 % 10;
            int b = prod / 10000 % 10;
            int c = prod / 1000 % 10;
            int d = prod / 100 % 10;
            int e = prod / 10 % 10;
            int f = prod % 10;

            if (a == f && b == e && c == d)
            {
                cout << prod;
                return 0;
            }
        }
    }
}