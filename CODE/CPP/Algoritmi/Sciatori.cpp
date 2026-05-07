#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N = 6;

void _print_vector(vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int sciatori_one(vector<int> people, vector<int> ski)
{
    sort(people.begin(), people.end());
    //_print_vector(people);
    sort(ski.begin(), ski.end());
    //_print_vector(ski);

    int diff = 0;
    for (size_t i = 0; i < 6; i++)
        diff += abs(people[i] - ski[i]);

    return diff;
}



int main(int argc, char const *argv[])
{
    vector<int> people = {5, 1, 9, 1, 3, 6};
    vector<int> ski = {3, 4, 1, 2, 5, 6};

    cout << endl<< sciatori_one(people, ski) << endl;
}
