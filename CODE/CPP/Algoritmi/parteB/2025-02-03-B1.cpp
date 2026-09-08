#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define N 3

using namespace std;

void printNumbers(vector<int> usable, string num = "")
{
    vector<int> next_usable = usable;
    int disabled;

    for (int i = 0; i < usable.size(); i++)
    {
        num.append(to_string(usable[i]));
        cout << num << endl;
        disabled = usable[i];
        next_usable.erase(next_usable.begin() + i);

        if (num.size() < N)
            printNumbers(next_usable, num);

        num.pop_back();
        next_usable.insert(next_usable.begin() + i, disabled);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> usable = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printNumbers(usable);

    return 0;
}
