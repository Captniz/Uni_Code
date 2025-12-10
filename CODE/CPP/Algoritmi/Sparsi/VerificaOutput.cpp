#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool areFilesEqual(const string &file1, const string &file2)
{
    ifstream f1(file1, ios::binary | ios::ate);
    ifstream f2(file2, ios::binary | ios::ate);

    // Se uno dei due non si apre → diversi
    if (!f1.is_open() || !f2.is_open())
    {
        cerr << "Errore apertura file.\n";
        return false;
    }

    // 1️⃣ Confronto dimensioni
    if (f1.tellg() != f2.tellg())
        return false;

    // 2️⃣ Torno all'inizio
    f1.seekg(0);
    f2.seekg(0);

    static const size_t BUFFER_SIZE = 4096;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];

    // 3️⃣ Confronto a blocchi
    while (f1 && f2)
    {
        f1.read(buffer1, BUFFER_SIZE);
        f2.read(buffer2, BUFFER_SIZE);

        if (f1.gcount() != f2.gcount())
            return false;

        if (memcmp(buffer1, buffer2, f1.gcount()) != 0)
            return false;
    }

    return true; // perfettamente uguali
}

int main()
{
    string file1, file2;
    file1 = "./ricostruzione-albero/output/output10.txt";
    file2 = "output.txt";

    if (areFilesEqual(file1, file2))
        cout << "✅ I file sono IDENTICI\n";
    else
        cout << "❌ I file sono DIVERSI\n";

    return 0;
}
