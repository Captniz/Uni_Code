using namespace std;

#include <iostream>

void Uno()
{
    srand(time(NULL));
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 9 + 0;
        cout << arr[i] << " ";
    }
}

void QuattroBis(int (&arr)[])
{
    int tmp = 0;

    for (int i = 0; i < (10 / 2); i++)
    {
        tmp = arr[i];
        arr[i] = arr[9 - i];
        arr[9 - i] = tmp;
    }
}

void Quattro()
{
    srand(time(NULL));
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 9 + 0;
        cout << arr[i] << " ";
    }
    cout << endl;

    QuattroBis(arr);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}

void CinqueBis(int (&arr)[], int n, int pos)
{
    cout << "Numero: " << n << " Posizione: " << pos << endl;

    for (int i = (10 - 1); i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = n;
}

void Cinque()
{
    srand(time(NULL));
    int arr[10];
    int n = 0;
    int pos = 0;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 9 + 0;
        cout << arr[i] << " ";
    }

    cout << endl
         << "Numero e posizione: " << endl;

    cin >> n >> pos;

    CinqueBis(arr, n, pos);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    Cinque();
}