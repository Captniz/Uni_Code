#include <iostream>
#include <fstream>

using namespace std;

int N;

int f(ifstream &in)
{
    int max = 0;
    int sum = 0;
    int curr;

    for (int i = 0; i < N; i++)
    {
        in >> curr;

        if (curr < 0)
        {
            if (max < sum)
                max = sum;

            if ((curr + sum) < 0)
            {
                sum = 0;
                continue;
            }
        }
        sum += curr;
    }

    if (max < sum)
        max = sum;

    return max;
}

int f2(ifstream &in)
{
    int max = 0;
    int sum = 0;
    int curr;

    for (int i = 0; i < N; i++)
    {
        in >> curr;
        sum += curr;

        if (max < sum)
            max = sum;

        if (sum < 0)
            sum = 0;
    }

    return max;
}

int main()
{
    ifstream in("input.txt");
    in >> N;

    ofstream out("output.txt");
    out << f(in);
    return 0;
}
