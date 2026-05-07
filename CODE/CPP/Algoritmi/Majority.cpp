#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N;
vector<int> numbers;

bool majority(int size)
{
    for (int i = 0; i < (size / 2); i++)
        if (numbers[i] == numbers[i + (size / 2)])
            return true;

    return false;
};

int main()
{
    in >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        in >> num;
        numbers.push_back(num);
    }

    cout << majority(N) << endl;

    in.close();
    out.close();
    return 0;
}