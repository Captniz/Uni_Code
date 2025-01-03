#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

// Insert solution hereafter

void print_clauses(int **arr);

int main(int argc, char const *argv[])
{
    if (argc < 1)
    {
        cout << "Error, file name not given";
        return 1;
    }

    fstream in = fstream(argv[1], ios::in);
    if (!in.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    char word[20] = "";
    int n_claus = 0;
    int n_vars = 0;

    in >> word;
    if (word != "p")
    {
        cout << "Error reading header of file " << argv[1];
        in.close();
        return 1;
    }
    in >> word;
    if (word != "cnf")
    {
        cout << "Error reading header of file " << argv[1];
        in.close();
        return 1;
    }
    in >> word;
    n_claus = atoi(word);
    if (n_claus <= 0)
    {
        cout << "Error reading header of file " << argv[1];
        in.close();
        return 1;
    }
    in >> word;
    n_vars = atoi(word);
    if (n_vars <= 0)
    {
        cout << "Error reading header of file " << argv[1];
        in.close();
        return 1;
    }

    int **claus = new int *[n_claus + 1];
    claus[n_claus] = nullptr;

    for (int i = 0; i < n_claus; i++)
    {
        int tmpvar = 0;
        claus[i] = new int[n_vars + 1];

        in >> claus[i][0]; // void it
        for (int j = 0; j < n_vars; j++)
        {
            if (in.eof())
            {
                cout << "Error reading file " << argv[1] << ": eof or clause out of bound, or 0 encountered, or more clauses encountered";
                in.close();
                delete[] claus;
                return 1;
            }
            in >> tmpvar;
            tmpvar = abs(tmpvar);

            if (tmpvar > n_vars || tmpvar == 0)
            {
                cout << "Error reading file " << argv[1] << ": eof or clause out of bound, or 0 encountered, or more clauses encountered";
                in.close();
                delete[] claus;
                return 1;
            }
            else
                claus[i][j];

            char cc = in.get();
            if ((cc != ' ' && (j + 1) < n_vars) || (cc != '\n' && (j + 1) >= n_vars))
            {
                cout << "Error reading file " << argv[1] << ": eof or clause out of bound, or 0 encountered, or more clauses encountered";
                in.close();
                delete[] claus;
                return 1;
            }
        }
        claus[i][n_vars] = 0;
    }

    if (!in.eof())
    {
        cout << "Error reading file " << argv[1] << ": eof or clause out of bound, or 0 encountered, or more clauses encountered";
        in.close();
        delete[] claus;
        return 1;
    }

    in.close();
}

void print_clauses(int **arr)
{
    int ctr;

    int i = 0,
        j = 0;
    while (arr[i] != nullptr)
    {
        j = 0;
        do
        {
            cout << arr[i][j] << " ";
            j++;
        } while (arr[i][j] != 0);
        cout << "\n";
        i++;
    }
    cout << "p cnf";
}