#include <iostream>
#include <cstring>
#include <fstream>
#include "../Snippets/Arrays.hpp"

using namespace std;

struct Paziente
{
    float peso;
    int eta;
    int dati[12][31];

    Paziente(fstream &file)
    {
        this->peso = file.get();
        this->eta = file.get();

        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 31; j++)
                dati[i][j] = file.get();
    }
};

void monitora(Paziente p, int mon, int &ipo, int ipr)
{
    float med = 0;
    int ipoc = 0;
    int iprc = 0;

    for (int i = 0; i < 31; i++)
    {
        med += p.dati[mon][i];

        if (p.dati[mon][i] < ipo)
            ipoc++;
        if (p.dati[mon][i] > ipr)
            iprc++;
    }
    med /= 31;

    cout << "Il numero di giorni di iperglicemia e': " << iprc << endl;
    cout << "il numero di giorni di ipoglicemia e':  " << ipoc << endl;
    cout << "la media e': " << med;
    cout <<"la varianza e'";
}

int main(int argc, char const *argv[])
{
    // Controllo sui arg
    if (argc != 5)
    {
        cout << "Il numero di parametri è diverso da 4. Errore!";
        return 1;
    }

    // Creo var
    fstream file(argv[1], ios::in);
    int mon = atoi(argv[2]);
    int ipo = atoi(argv[3]);
    int ipr = atoi(argv[4]);

    // Controlli su var
    if (!file.is_open())
    {
        cout << "Il file non esiste. Errore!";
        return 1;
    }

    if ((ipo > ipr) || (ipo < 80 || ipo > 95) || (ipr < 105 || ipr > 120))
    {
        cout << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!";
        return 1;
    }
    if (mon < 1 || mon > 12)
    {
        cout << "Il mese non è valido. Errore!";
        return 1;
    }

    return 0;
}
