#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*There is a stack of water glasses in the form of a Pascal triangle and a person wants to pour the water at the topmost glass, but the capacity of each glass is 1 unit. Overflow occurs in such a way that after 1 unit, 1/2 of the remaining unit gets into the bottom left glass and the other half in the bottom right glass. We pour k units of water into the topmost glass. The task is to find how much water is there in the c'th glass of the r'th row.

Note: Assume that there are enough glasses in the triangle till no glass overflows.

//!O(r^2) time and O(r^2) Space

*/

float fillGlass(vector<vector<float>> dp, int row, int col)
{
    int rowglasses = pow(2, row);
    int halfrow = int((rowglasses + 1) / 2);

    if (col < halfrow) // Se sono nella prima meta'
        if (col == 0)  // Se  e' il primo
            return (dp[row - 1][col] / 2.0);
        else
            return ((dp[row - 1][col] / 2.0) + (dp[row - 1][col + 1] / 2.0));
    else                             // Seconda meta'
        if (col == (rowglasses - 1)) // Se è l'ultimo
            return (dp[row - 1][col - 1] / 2.0);
        else
            return ((dp[row - 1][col] / 2.0) + (dp[row - 1][col - 1] / 2.0));
    return -400.0; //! Usa mod (%1) per togliere la quantita di acqua
}

float overflow(float pour, int rows, int glass)
{
    // make dp
    vector<vector<float>> dp = vector<vector<float>>(rows);
    for (int i = 0; i < rows; i++)
        dp[i] = vector<float>(pow(2, i), 0.0);

    // dp contains the remainder of water in each glass after pouring the water in the topmost glass

    dp[0][0] = (pour >= 1 ? (pour - 1) : pour);

    for (int i = 0; i < rows; i++)
    {
        if (pour <= 0)
            break;

        int curr_row_glasses = int(pow(2, i));

        for (int j = 0; j < curr_row_glasses; j++)
            dp[i][j] = fillGlass(dp, i, j); //! rimuovi da pour
    }

    return dp[(rows - 1)][glass];
}

// 0
// 1 1
// 2 2 2
// 3 3 3 3
int main(int argc, char const *argv[])
{
    cout << overflow(2, 2, 2);
    return 0;
}
