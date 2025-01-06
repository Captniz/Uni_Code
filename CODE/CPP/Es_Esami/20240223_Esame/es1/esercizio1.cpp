#include <iostream>
#include <fstream>

// Inserire qui sotto la soluzione all'esercizio
using namespace std;

fstream OpenFile_Utl(string filename, ios_base::openmode mode);
float Percentuale(int magg, int tot);

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cout << "Error: Number of arguments invalid";
        return 1;
    }

    fstream mot1 = OpenFile_Utl(argv[1], ios_base::in);
    fstream mot2 = OpenFile_Utl(argv[2], ios_base::in);

    int tot = 0;
    int mag = 0;

    while (!mot1.eof() && (mot1.peek() != EOF))
    {
        float t1, t2;
        mot1 >> t1;
        mot2 >> t2;
        tot++;
        if (t1 > t2)
            mag++;
    }

    if (tot == 0)
    {
        cout << "Il numero delle misurazioni e’ uguale a zero, per cui non posso calcolare la percentuale";

        return 0;
    }

    cout << "La percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2 e’ del " << Percentuale(mag, tot) << "%";

    return 0;
}

float Percentuale(int mag, int tot)
{
    // mag:tot = x:100

    return ((float)mag / (float)tot) * (float)100;
}

fstream OpenFile_Utl(string filename, ios_base::openmode mode)
{
    fstream file;
    file.open(filename, mode);
    if (!file)
    {
        cout << "Errore nell'apertura del file." << endl;
        exit(1);
    }
    return file;
}