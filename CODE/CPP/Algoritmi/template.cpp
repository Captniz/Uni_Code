#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N; 


int main()
{
    in >> N;

    in.close();
    out.close();
    return 0;
}