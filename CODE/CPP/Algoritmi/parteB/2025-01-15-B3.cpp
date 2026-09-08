#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void cph(int N, int openers_available, int to_close = 1, string sequence = "(")
{
    if (openers_available == 0 && to_close == 0)
        cout << sequence << endl;

    if (openers_available > 0)
        cph(N, openers_available - 1, to_close + 1, sequence + "(");

    if (to_close > 0)
        cph(N, openers_available, to_close - 1, sequence + ")");
}
void countPars(int n)
{
    cph(n, n - 1);
}
int main(int argc, char const *argv[])
{
    countPars(3);
    return 0;
}
