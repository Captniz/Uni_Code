using namespace std;

#include <iostream>
#include <string>
#include <stack>

void DueBis(char &a)
{
    a += 'A' - 'a';
}
void Due()
{
    char a;
    cin >> a;

    if (a >= 'a' && a <= 'z')
    {
        DueBis(a);
    }
    cout << a;
}

int TreBis(int n)
{
    int res = 0;
    while (n > 0)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

void Tre()
{
    int n;
    cin >> n;
    cout << TreBis(n);
}

void Cinque()
{
    int row, col;
    cin >> row >> col;
    cout << !((col == 1) || (row == 1));
}

int main()
{
    Tre();
}
