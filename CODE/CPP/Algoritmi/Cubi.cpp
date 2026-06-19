#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");

class Cubo
{
public:
    string values;

    Cubo(string values)
    {
        this->values = values;
    }

    char getFace(int face)
    {
        return values[face];
    }
};

void fillLetters(char *letters[], string word)
{
    int word_chars = word.size();
}

bool canWrite(vector<Cubo> *cubes, string word)
{
    int word_chars = word.size();
    char letters[word_chars];
}

int main()
{
    int n_cubi = 6;
    vector<Cubo> cubi;
    string word = "DADI";

    

    for (int i = 0; i < n_cubi; i++)
    {
        string values;
        in >> values;
        cubi.push_back(Cubo(values));
    }

    cout << canWrite(&cubi, "DADI");

    return 0;
}