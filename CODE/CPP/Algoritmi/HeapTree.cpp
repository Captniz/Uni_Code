#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N;

class HeapTree
{
private:
    vector<int> *heap;

public:
    HeapTree()
    {
        heap = new vector<int>();
    }

    HeapTree(int size, int init)
    {
        heap = new vector<int>(size, init);
    }

    
};

main()
{
    in >> N;

    in.close();
    out.close();
    return 0;
}