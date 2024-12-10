using namespace std;

#include <iostream>

int UnoBis(int n, int res = 1)
{
    if (n == 0)
    {
        return res;
    }
    else
    {
        return UnoBis(n - 1, res * n);
    }
}

void Uno()
{
    int n;
    cin >> n;

    cout << UnoBis(n) << endl;
}

void TreBis(int n, int i)
{
    
}
void Tre()
{
    int n;
    cin >> n;

    TreBis();
}

int main()
{
    Uno();
}