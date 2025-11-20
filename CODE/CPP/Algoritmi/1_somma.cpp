#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a, b;
    ifstream in("input.txt");
    in >> a >> b;
    ofstream out("output.txt");
    out << b + a;
    return 0;
}