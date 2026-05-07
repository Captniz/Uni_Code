#include <iostream>
#include <vector>

using namespace std;

int FixPalindrome(int **dp, string *s, int left, int right)
{
    if (left >= right)
        return 0;

    if (dp[left][right] != -1)
        return dp[left][right];

    if (s->at(left) == s->at(right))
        dp[left][right] = FixPalindrome(dp, s, left + 1, right - 1);
    else
        dp[left][right] = 1 + min(
                                  FixPalindrome(dp, s, left + 1, right),
                                  FixPalindrome(dp, s, left, right - 1));

    return dp[left][right];
}

int main(int argc, char const *argv[])
{
    string s = "ant";
    int **dp = new int *[s.size()];
    for (int i = 0; i < s.size(); i++)
        dp[i] = new int[s.size()];

    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < s.size(); j++)
            dp[i][j] = (i == j ? 0 : -1);

    cout << FixPalindrome(dp, &s, 0, s.size() - 1);
    return 0;
}
