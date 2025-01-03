/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start

#include <iostream>
using namespace std;

class Solution
{
public:
    char *convert(char s[], int numRows)
    {
        int numSpaces = numRows - 2;
        int ctr = 0;

        for (int i = 0; i < numRows; i += numRows + numSpaces)
        {
            cout << s[i];

            for (int j = 0; j < numSpaces; j++)
                cout << " ";
        }
        for (int i = 0; i < numRows; i += numRows + numSpaces)
        {
            cout << s[i];

            for (int j = 0; j < numSpaces; j++)
                cout << " ";
        }
    }
};
// @lc code=end
