using namespace std;

#include <iostream>
#include "Snippets/Snippets.hpp"
#define ROW 5
#define COL 5

void Due()
{
    int **mat = mat::Random_Mat(ROW, COL, 0, 10);
    mat::Print_Mat(mat, ROW, COL);
    cout << endl;
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }
}

void Tre()
{
    int **mat = mat::Random_Mat(ROW, COL, 0, 1);
    mat::Print_Mat(mat, ROW, COL);
    int ctr = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            j >= i ? ctr += mat[i][j] : 0;
        }
    }
    cout << ctr << endl;
}

void Quattro()
{
    double **mat = new double *[3];
    mat[0] = new double[3]{1, 0, 2};
    mat[1] = new double[3]{2, 1, 0};
    mat[2] = new double[3]{1, 3, 1};
    mat::Print_Mat(mat, 3, 3);
    double **matc = mat::Copy_Mat(mat, 3, 3);
    double med = 0;
    double size = 0;

    mat::Print_Mat(mat, 3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat::CoordsValid_Mat(3, 3, i + 1, j))
            {
                med += mat[i + 1][j];
                size++;
            }
            if (mat::CoordsValid_Mat(3, 3, i - 1, j))
            {
                med += mat[i - 1][j];
                size++;
            }
            if (mat::CoordsValid_Mat(3, 3, i, j + 1))
            {
                med += mat[i][j + 1];
                size++;
            }
            if (mat::CoordsValid_Mat(3, 3, i, j - 1))
            {
                med += mat[i][j - 1];
                size++;
            }
            med /= size;
            matc[i][j] = med;
            med = 0;
            size = 0;
        }
    }

    cout << endl;
    mat::Print_Mat(matc, 3, 3);
}

int CBis(int row, int col, int (&mat)[ROW][COL], int *values)
{
    int result = 0;

    if (mat[row][col] == 1)
    {
        if (COL - 1 == col)
        {
            values[col] = row;
            return 1;
        }
        switch (row)
        {
        case 0:
            result += CBis(row, col + 1, mat, values);
            result += CBis(row + 1, col + 1, mat, values);
            break;
        case (ROW - 1):
            result += CBis(row - 1, col + 1, mat, values);
            result += CBis(row, col + 1, mat, values);
            break;
        default:
            result += CBis(row - 1, col + 1, mat, values);
            result += CBis(row, col + 1, mat, values);
            result += CBis(row + 1, col + 1, mat, values);
            break;
        }
        if (result > 0)
        {
            values[col] = row;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void Cinque()
{
    int mat[ROW][COL] = {
        {1, 1, 0, 1, 0},
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0}};

    int *values = new int[COL];

    for (int i = 0; i < ROW; i++)
    {
        if (CBis(i, 0, mat, values) == 1)
        {
            for (int j = 0; j < COL; j++)
            {
                cout << values[j] << " ";
            }
            cout << endl;
            break;
        }
    }
}

bool SeiBis(int **mat, int x, int y)
{
    bool isolated = true;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (mat::CoordsValid_Mat(10, 10, x + i, y + j) && (i != 0 || j != 0))
            {
                if (mat[x + i][y + j] == 1)
                {
                    isolated = false;
                    break;
                }
            }
        }
    }
    return isolated;
}

void Sei()
{
    int **mat = mat::Random_Mat(10, 10, 0, 1);
    mat::Print_Mat(mat, 10, 10);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mat[i][j] == 1)
            {
                if (SeiBis(mat, i, j))
                {
                    cout << "Isola in coord: " << i << "-" << j << endl;
                }
            }
        }
    }
}

void Sette()
{

    int **mat = new int *[3];
    mat[0] = new int[3]{1, 0, 3};
    mat[1] = new int[3]{0, -2, 5};
    mat[2] = new int[3]{4, 1, 0};
    mat::Print_Mat(mat, 3, 3);
    int det = 0;

    for (int i = 0; i < 3; i++)
    {
        int add = 1;
        int sub = 1;
        for (int j = 0; j < 3; j++)
        {
            add *= mat[j][(i + j) % 3];
            sub *= mat[j][(i + 2 - j) % 3];
        }
        det += add - sub;
    }

    cout << det << endl;
}

int main()
{
    Sette();
    return 0;
}