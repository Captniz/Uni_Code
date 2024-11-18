/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // badabumubadabam
        // acaca

        string pal = s.substr(0, 1);

        if (s.size() == 1)
            return s;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = s.size() - 1; j > i; j--)
            {
                if (s[i] == s[j])
                {
                    int k;
                    int start = i;
                    int end = j;
                    int len = end - start + 1;

                    for (k = 0; k < len / 2; k++)
                    {
                        if (s[start + k] != s[end - k])
                        {
                            break;
                        }
                    }
                    if (k == len / 2) // May break because of k == len/2
                    {
                        if (len > pal.size())
                        {
                            pal = s.substr(start, len);
                        }
                    }
                }
            }
        }

        return pal;
    }
};
// @lc code=end
