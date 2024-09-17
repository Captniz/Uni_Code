using namespace std;

#include <iostream>

void TabVerita()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << i << " && " << j << " : " << (i && j) << endl;
            cout << i << " || " << j << " : " << (i || j) << endl;
            cout << endl;
        }
    }
}

void Minuscolo()
{
    char c;
    do
    {
        cout << "Inserisci un carattere maiuscolo: ";
        cin >> c;
    } while (c < 'A' || c > 'Z');

    c = c + 32;
    cout << "Il carattere in minuscolo è: " << c << endl;
}

int main(int argc, char const *argv[])
{
    Minuscolo();
    return 0;
}
