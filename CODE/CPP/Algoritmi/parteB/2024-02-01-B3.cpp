#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define N 7

void print_vector(vector<int> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int lcncs(string s, string u)
{
    if (u.length() < s.length())
        swap(s, u);

    vector<int> DP = vector<int>(s.length() + 1, 0);

    int last = 0;
    bool found = false;
    for (int i = 0; i < s.length(); i++)
    {
        DP[i + 1] = DP[i];
        if (found)
        {
            found = false;
            continue;
        }
        for (int j = i; j >= last; j--)
        {
            if (s.at(i) == u.at(j))
            {
                DP[i + 1]++;
                found = true;
                last = j + 2;
                break;
            }
        }
    }

    return DP[s.length()];
}

int main(int argc, char const *argv[])
{
    lcncs("abcd", "bcbd");
    return 0;
}
