/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        int pos = 0;

        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;

        for (int i = 1; i < s.size(); i++)
        {
            for (int j = i - 1; j >= pos; j--)
            {
                if (s[i] == s[j])
                {
                    if (len < i - pos)
                        len = i - pos;
                    pos = j + 1;
                    break;
                }
            }
        }

        return len > s.size() - pos ? len : s.size() - pos;
    };
};
// @lc code=end
