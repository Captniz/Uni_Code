using namespace std;

#include <iostream>
#include <string>
#include <stack>

int CalcolaPunti(int punti)
{
    if (punti == 1)
    {
        return 11;
    }
    else if (punti > 10)
    {
        return 10;
    }
    else
    {
        return punti;
    }
}

class Carta
{
public:
    int Seme = 0;
    // 0 = Cuori, 1 = Quadri, 2 = Fiori, 3 = Picche
    int Valore = 0;
    // 1 = Asso, 2-10 = 2-10, 11 = Fante, 12 = Regina, 13 = Re
};

int main()
{
    srand(time(NULL));

    //! ### CREO MAZZO ###

    string Semi[] = {"Cuori", "Quadri", "Fiori", "Picche"};
    string Nomi[] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack", "Regina", "Re"};
    Carta Mazzo[52];

    for (int i = 0; i < 52; i++)
    {
        Mazzo[i].Seme = i / 13;
        Mazzo[i].Valore = i % 13 + 1;
    }

    //! ### MESCOLO MAZZO ###

    stack<Carta> MazzoMisto;
    int count = 0;
    int selected = 0;

    for (int i = 0; i < 52; i++)
    {
        srand(time(NULL));
        selected = rand() % (52 - count) + count;

        MazzoMisto.push(Mazzo[selected]);
        count++;
        Mazzo[selected] = Mazzo[i];
    }

    //! ### DO CARTE ###

    int Giocatori = 0;
    int PuntiDealer = 0;

    cout << "Giocatori:";
    cin >> Giocatori;

    int PuntiGiocatori[Giocatori];

    cout << "Il dealer ha " << Nomi[MazzoMisto.top().Valore - 1] << " di " << Semi[MazzoMisto.top().Seme] << endl;
    PuntiDealer += CalcolaPunti(MazzoMisto.top().Valore);
    cout << "Il dealer ha " << PuntiDealer << " punti" << endl
         << endl;
    MazzoMisto.pop();

    for (int i = 0; i < Giocatori; i++)
    {
        PuntiGiocatori[i] = 0;
        for (int j = 0; j < 2; j++)
        {
            cout << "Il giocatore " << i + 1 << " ha " << Nomi[MazzoMisto.top().Valore - 1] << " di " << Semi[MazzoMisto.top().Seme] << endl;
            PuntiGiocatori[i] += CalcolaPunti(MazzoMisto.top().Valore);
            MazzoMisto.pop();
        }
        cout << "Il giocatore " << i + 1 << " ha " << PuntiGiocatori[i] << " punti" << endl
             << endl;
    }

    //! ### GIOCO ###

    int flag = 1;
    int choice = 0;

    for (int i = 0; i < Giocatori; i++)
    {
        choice = 0;
        flag = 1;
        while (flag)
        {
            cout << "Il giocatore " << i + 1 << " vuole un'altra carta? (1 = Si, 0 = No):";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Il giocatore " << i + 1 << " ha " << Nomi[MazzoMisto.top().Valore - 1] << " di " << Semi[MazzoMisto.top().Seme] << endl;
                PuntiGiocatori[i] += CalcolaPunti(MazzoMisto.top().Valore);
                cout << "Il giocatore " << i + 1 << " ha " << PuntiGiocatori[i] << " punti" << endl
                     << endl;
                MazzoMisto.pop();
                if (PuntiGiocatori[i] > 21)
                {
                    cout << "Il giocatore " << i + 1 << " ha sballato" << endl
                         << endl;
                    flag = 0;
                }
            }
            else
            {
                flag = 0;
            }
        }
        flag = 1;
    }

    cout << endl
         << endl
         << "TURNO DEL DEALER" << endl
         << endl;

    while (PuntiDealer <= 17)
    {
        cout << "Il dealer ha chiesto un'altra carta" << endl;
        cout << "Il dealer ha " << Nomi[MazzoMisto.top().Valore - 1] << " di " << Semi[MazzoMisto.top().Seme] << endl;
        PuntiDealer += CalcolaPunti(MazzoMisto.top().Valore);
        cout << "Il dealer ha " << PuntiDealer << " punti" << endl
             << endl;
        MazzoMisto.pop();
    }

    if (PuntiDealer > 21)
    {
        cout << "Il dealer ha sballato" << endl
             << endl;
    }
    else
    {
        for (int i = 0; i < Giocatori; i++)
        {
            if (PuntiGiocatori[i] > PuntiDealer && PuntiGiocatori[i] <= 21)
            {
                cout << "Il giocatore " << i + 1 << " ha vinto" << endl;
            }
            else if (PuntiGiocatori[i] == PuntiDealer)
            {
                cout << "Il giocatore " << i + 1 << " ha pareggiato" << endl;
            }
            else
            {
                cout << "Il giocatore " << i + 1 << " ha perso" << endl;
            }
        }
    }

    return 0;
}
