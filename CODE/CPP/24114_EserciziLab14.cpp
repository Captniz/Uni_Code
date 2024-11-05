using namespace std;

#include <iostream>
#define ROW 5
#define COL 5

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

int main()
{
    return 0;
}