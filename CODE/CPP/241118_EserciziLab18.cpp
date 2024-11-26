using namespace std;

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Snippets/Snippets.hpp"

void Uno()
{

    fstream in, out;
    in.open("input.txt", ios::in);
    out.open("output.txt", ios::out);

    if (!in || !out)
    {
        cout << "Errore apertura file di input" << endl;
        return;
    }

    int pas = mix::InputInt_Mix("Inserisci i passi del cifrario: ");
    char c = in.get();

    while (c != EOF)
    {
        if (c > 64 && c < 91)
        {
            c = 65 + ((c - 65 + pas) % 26);
        }
        else if (c > 96 && c < 123)
        {
            c = 97 + ((c - 97 + pas) % 26);
        }

        out << c;
        c = in.get();
    }
}

char *Due(char str[], int pos = 0, int upper = 0)
{

    if (str[pos] == '\0')
    {
        char *ret = str::Substr_Str(str, upper, pos);
        str[upper] = '\0';
        return ret;
    }

    if (str[pos] > 64 && str[pos] < 91) // se è maiuscola
    {
        return Due(str, pos + 1, upper);
    }
    else
    {
        char tmp;
        tmp = str[pos];
        str[pos] = str[upper];
        str[upper] = tmp;
        return Due(str, pos + 1, upper + 1);
    }
}

bool TreBis(char *str)
{
    int len = strlen(str);
    int i = 0;
    int flag = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '@') // Cerco la chiocciola
        {
            if (flag != 0)                    // Se ne trovo più di una
                return false;                 // Restituisco false
            flag = i;                         // Altrimenti salvo la posizione
            if (flag == 0 || flag == len - 1) // Se la chiocciola è in prima o ultima posizione
                return false;                 // Restituisco false
        }
        if ( // Se trovo un carattere non valido
            str[i] != '.' &&
            str[i] != '@' &&
            !('a' <= str[i] && str[i] >= 'z') &&
            !('A' <= str[i] && str[i] >= 'Z'))
            return false; // Restituisco false
    }

    if (!flag)        // Se non ho trovato la chiocciola
        return false; // Restituisco false

    if ( // Se la chiocciola è seguita o preceduta da un punto
        str[0] == '.' ||
        str[len - 1] == '.' ||
        str[flag - 1] == '.' ||
        str[flag + 1] == '.')
        return false; // Restituisco false

    return true;
}

void Tre()
{
    fstream in, out;
    in.open("input.txt", ios::in);
    out.open("output.txt", ios::out);

    if (!in || !out)
    {
        cout << "Errore apertura file di input" << endl;
        return;
    }

    while (!in.eof())
    {
        char *str = new char[256];
        in.getline(str, 256);

        if (TreBis(str))
            out << str << endl;
    }
}

bool QuattroBis(char **mat, int row, int col, char sym)
{
    int win = 3;
    for (int i = 0; i < 3; i++)
    {
        if (mat[row][i] != sym)
        {
            win--;
            break;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (mat[i][col] != sym)
        {
            win--;
            break;
        }
    }



}

void Quattro()
{
    char mat[3][3];
    mat::Zero_Mat((char **)mat, 3, 3);

    bool flag = false;
    cout << "Hai Le X" << endl;

    while (true)
    {
        {
            system("clear");
            cout << "┌─┬─┬─┐" << endl;
            cout << "│" << mat[0][0] << "│" << mat[0][1] << "│" << mat[0][2] << "│" << endl;
            cout << "├─┼─┼─┤" << endl;
            cout << "│" << mat[1][0] << "│" << mat[1][1] << "│" << mat[1][2] << "│" << endl;
            cout << "├─┼─┼─┤" << endl;
            cout << "│" << mat[2][0] << "│" << mat[2][1] << "│" << mat[2][2] << "│" << endl;
            cout << "└─┴─┴─┘" << endl;
        }

        if (flag)
        {
            int row, col;
            bool success = false;

            cout << "Turno del giocatore" << endl;

            do
            {
                cout << "Coordinate ( row,col ): ";
                cin >> row >> col;

                if (mat[row][col] == ' ')
                {
                    mat[row][col] = 'X';
                    success = true;
                }
                else
                    cout << "Mossa non valida" << endl;

            } while (success);
        }
        else
        {
            int row, col;
            bool success = false;

            cout << "Turno del computer" << endl;

            do
            {
                row = mix::Random_Mix(2, 0);
                col = mix::Random_Mix(2, 0);

                if (mat[row][col] == ' ')
                {
                    mat[row][col] = 'O';
                    success = true;
                }
            } while (success);
        }

        flag = !flag;
    }
}

int main(int argc, char *argv[])
{
    Quattro();
}