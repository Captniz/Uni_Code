using namespace std;

#include <iostream>
#include <string>
#include <stack>

void Uno()
{
    int a, b;
    cin >> a >> b;
    int res = a - b;
    int mod = (-(res < 0)) + (res > 0); // 1 se neg, 0 se pos
    cout << res * mod;
}

void Due()
{
    int a, b;
    int max = 0, min = 0;
    cin >> a >> b;
    int mod = a > b;

    max = (a * mod) + (b * !mod);

    cout << "max: " << max;
}

void Quattro(){
    int a, b;
    cin >> a >> b;
    cout << !(a!=b);   
}

void Cinque(){
    int row, col;
    cin >> row >> col;
    cout<< !((col==1) || (row==1));
}

int main()
{
    Cinque();
}
