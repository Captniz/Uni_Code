using namespace std;

#include <iostream>
#include <string>
#include <stack>

void UnoBis(double *a, double *b)
{
    // Scambia
    double temp = *a;
    *a = *b;
    *b = temp;
}

void Uno()
{
    double a, b;
    cout << "Inserisci due numeri: ";
    cin >> a >> b;
    UnoBis(&a, &b);
}

float DueBis(int &a, int b)
{
    int q = 0;
    while (a >= b)
    {
        a -= b;
        q++;
    }
    return q;
}

void Due()
{
    /*Dati in input due interi, scrivere un programma che faccia la divisione
    tramite una funzione; la funzione restituisce tramite valore di ritorno il
    quoziente e tramite parametro per riferimento il resto.
    In questo programma non si può usare il simbolo ‘/’ per la divisione*/

    int a, b;
    cout << "Inserisci due numeri: ";
    cin >> a >> b;
    b = DueBis(a, b);
    cout << b << " " << a;
}

void TreBis(int &sec, int &min, int &hrs)
{
    min += sec / 60;
    sec %= 60;
    hrs += min / 60;
    min %= 60;
}

void Tre()
{
    int sec, min, hrs;
    cout << "Inserisci sec, min, hrs: ";
    cin >> sec >> min >> hrs;
    TreBis(sec, min, hrs);
    cout << sec << " " << min << " " << hrs;
}

void QuattroBis(int a, int b, int c = 0, int d = 0, int e = 0, int f = 0)
{
    // Max
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;
    if (e > max)
        max = e;
    if (f > max)
        max = f;
    cout << "Max: " << max << endl;
}



int main()
{
}
