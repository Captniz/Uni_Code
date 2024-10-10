using namespace std;

#include <iostream>

void Due()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        cout << char(i) << ' ';
    }
    cout << endl;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        cout << char(i) << ' ';
    }
}

int QuattroBis(int num, int **primi)
{
    int *primiTmp = (int *)malloc(num * sizeof(int));
    int len = 0;
    int ctr = 0;

    for (int i = 1; i < num; i += 2)
    {
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                ctr++;
            }
        }
        if (ctr <= 1)
        {
            primiTmp[len] = i;
            len++;
        }
        ctr = 0;
    }

    *primi = (int *)realloc(primiTmp, len * sizeof(int));

    return len;
}

void Quattro()
{
    // Input
    int num;
    cin >> num;

    // Check iniziale di possibilita
    if (num % 2 != 0)
    {
        cout << "Non possibile";
        return;
    }

    // Ricerca primi
    int *primi;
    int len = QuattroBis(num, &primi);

    // Output
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (primi[i] + primi[j] == num)
            {
                cout << primi[i] << " + " << primi[j] << " = " << num << endl;
            }
        }
    }
}

void Cinque()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int SeiBis(int n)
{
    int fat = 1;

    for (int i = 0; i < n; i++)
    {
        fat *= (n - i);
    }

    return fat;
}

void Sei()
{
    // r! / (r - c)! * c!

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << SeiBis(i) / (SeiBis(i - j) * SeiBis(j)) << " ";
        }
        cout << endl;
    }
}

int main()
{
    Quattro();
}