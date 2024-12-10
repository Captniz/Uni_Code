using namespace std;

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "Snippets/Snippets.hpp"
#define MAX 100

struct Studente
{
public:
    char nome[30];
    char cognome[30];
    int matricola;
    float media;
};

struct Database
{

    // ### Constructors ###

private:
    Studente *studenti;
    int size;
    int capacity;

    // ### Methods ###

public:
    Database(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        studenti = new Studente[capacity];
    }

    // ### Methods ###

    void StampaTot()
    {
        for (int i = 0; i < size; i++)
        {
            StampaStud(i);
            cout << endl;
        }
    }

    void StampaStud(Studente s)
    {
        cout << "Nome: " << s.nome << endl;
        cout << "Cognome: " << s.cognome << endl;
        cout << "Matricola: " << s.matricola << endl;
        cout << "Media: " << s.media << endl;
    }

    void StampaStud(int i)
    {
        Studente s = studenti[i];
        cout << "Nome: " << s.nome << endl;
        cout << "Cognome: " << s.cognome << endl;
        cout << "Matricola: " << s.matricola << endl;
        cout << "Media: " << s.media << endl;
    }

    int AppendStud(char nome[], char cognome[], int matricola, float media)
    {
        if (size < capacity)
        {
            Studente s;
            strcpy(s.nome, nome);
            strcpy(s.cognome, cognome);
            s.matricola = matricola;
            s.media = media;
            studenti[size] = s;
            size++;
        }
        else
        {
            cout << "Database pieno!" << endl;
            return -1;
        }
        return 0;
    };

    void CreateStud()
    {
        char nome[30], cognome[30];
        int matricola;
        float media;

        cout << "Inserisci nome: ";
        cin >> nome;
        cout << "Inserisci cognome: ";
        cin >> cognome;
        cout << "Inserisci matricola: ";
        cin >> matricola;
        cout << "Inserisci media: ";
        cin >> media;

        AppendStud(nome, cognome, matricola, media);
    }

    void FillFromFile(char file[])
    {
        fstream in;
        in.open(file, ios::in);

        if (!in)
        {
            cout << "Errore apertura file!" << endl;
            return;
        }

        char nome[30], cognome[30];
        int matricola;
        float media;

        while (!in.eof())
        {
            in >> nome >> cognome >> matricola >> media;
            if (AppendStud(nome, cognome, matricola, media) == 1)
            {
                break;
            };
        }

        in.close();
        return;
    }

    void CercaMat(int mat)
    {
        for (int i = 0; i < size; i++)
        {
            if (studenti[i].matricola == mat)
            {
                StampaStud(i);
                break;
            }
        }

        delete[] studenti;
    }

    void CercaNomeCognome(char nome[], char cognome[])
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(studenti[i].nome, nome) == 0 && strcmp(studenti[i].cognome, cognome) == 0)
            {
                StampaStud(i);
                break;
            }
        }

        delete[] studenti;
    }
};

int main(int argc, char const *argv[])
{
    Database studenti = Database(MAX);
    cout << "DB inizializzato!" << endl;

    while (true)
    {
        system("clear");
        cout << "Scegli un'opzione:" << endl;
        cout << "0. Carica da file" << endl;
        cout << "1. Aggiungi studente" << endl;
        cout << "2. Cerca studente per matricola" << endl;
        cout << "3. Cerca studente per nome e cognome" << endl;
        cout << "4. Stampa tutti gli studenti" << endl;
        cout << "5. Stampa studente per indice" << endl;
        cout << "6. Esci" << endl;
        cout << "Scelta: ";

        int scelta;
        cin >> scelta;

        cout << endl
             << endl;

        switch (scelta)
        {
        case 0:
            char file[30];
            cout << "Inserisci nome file: ";
            cin >> file;
            studenti.FillFromFile(file);
            break;

        case 1:
            studenti.CreateStud();
            break;

        case 2:
            int mat;
            cout << "Inserisci matricola: ";
            cin >> mat;
            studenti.CercaMat(mat);
            break;

        case 3:
            char nome[30], cognome[30];
            cout << "Inserisci nome: ";
            cin >> nome;
            cout << "Inserisci cognome: ";
            cin >> cognome;
            studenti.CercaNomeCognome(nome, cognome);
            break;

        case 4:
            studenti.StampaTot();
            break;

        case 5:
            int i;
            cout << "Inserisci indice: ";
            cin >> i;
            studenti.StampaStud(i);
            break;

        case 6:
            return 0;
            break;

        default:
            cout << "Scelta non valida!" << endl;
            break;
        }

        cout << "Premi un tasto per continuare...";
        cin.ignore();
        getchar();
    }
}
