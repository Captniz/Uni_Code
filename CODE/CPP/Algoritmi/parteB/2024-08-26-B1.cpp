#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void minMoves(string s)
{
    string target = "";
    target.append(s.substr(0, 1));
    int moves = 1;

    while (s != target)
    {
        moves++;

        int target_len = target.length();

        if (target_len * 2 <= s.length())
            if (target == s.substr(target_len, target_len))
            {
                target.append(target);
                continue;
            }

        target.push_back(s.at(target_len));
    }

    cout << target << endl;
    cout << moves;
}
int main(int argc, char const *argv[])
{
    minMoves("tatatami");
    return 0;
}
