#include <iostream>

using namespace std;

const int SIDE = 3;

struct Point
{
    int x;
    int y;
};

pair<Point, Point> *QuadBin(int mat[SIDE][SIDE])
{
    int max_side = 1;
    Point first;
    Point second;

    int DP_VERT[SIDE][SIDE];
    int DP_ORIZZ[SIDE][SIDE];

    DP_ORIZZ[0][0] = DP_VERT[0][0] = mat[0][0];

    for (int i = 1; i < SIDE; i++)
    {
        DP_ORIZZ[0][i] = mat[0][i] * (mat[0][i - 1] + 1);
        DP_VERT[0][i] = mat[0][i];
    }

    for (int i = 1; i < SIDE; i++)
    {
        DP_ORIZZ[i][0] = mat[i][0] * mat[i - 1][0];
        DP_VERT[i][0] = DP_ORIZZ[i][0] * (DP_ORIZZ[i - 1][0] + 1);
    }

    for (int i = 1; i < SIDE; i++)
    {
        for (int j = 1; j < SIDE; j++)
        {
            DP_ORIZZ[i][j] = mat[i - 1][j] * mat[i][j] * (DP_ORIZZ[i][j - 1] + 1);
            DP_VERT[i][j] = (DP_ORIZZ[i][j] == 0) ? 0 : (DP_ORIZZ[i][j] == DP_ORIZZ[i - 1][j] ? (DP_VERT[i - 1][j] + 1) : 1);

            if (DP_ORIZZ[i][j] == max_side && DP_VERT[i][j] >= max_side - 1)
            {
                second.x = i;
                second.y = j;

                first.x = i - max_side + 1;
                first.y = j - max_side + 1;

                max_side++;
            }
        }
    }

    return new pair<Point, Point>(first, second);
}

int main(int argc, char const *argv[])
{
/*     int mat[SIDE][SIDE] = {{1, 0, 1, 0, 1, 1, 0},
                           {1, 0, 1, 1, 1, 1, 0},
                           {0, 1, 1, 0, 1, 1, 0},
                           {0, 0, 1, 1, 0, 1, 0},
                           {1, 1, 1, 1, 1, 1, 0},
                           {1, 1, 0, 1, 1, 1, 0},
                           {0, 0, 0, 1, 1, 1, 0}}; */

    int mat[SIDE][SIDE] = {{1, 0, 1},
                           {1, 1, 1},
                           {0, 1, 1}};

    pair<Point, Point> *res = QuadBin(mat);

    cout << endl
         << "(" << res->first.x << " " << res->first.y << ")";
    cout << "(" << res->second.x << " " << res->second.y << ")";

    return 0;
}
