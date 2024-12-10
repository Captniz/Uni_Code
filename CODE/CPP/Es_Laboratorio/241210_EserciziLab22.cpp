#include <iostream>
#include "../Snippets/Utilities.hpp"
#include "../Snippets/Strings.hpp"
#include "../Snippets/Arrays.hpp"
#include "../Snippets/Matrix.hpp"

using namespace std;
using namespace utl;
using namespace arr;
using namespace mat;
using namespace str;

bool Due(int *arr, int dim)
{
    /*Scrivere un programma che verifichi in modo ricorsivo se una sequenza
    di numeri contenuta in un array di al più 100 interi è palindroma.

    Chiedere all’utente la dimensione dell’array (controllare sia <=100),
    acquisire gli elementi e infine controllare se palindroma.

    Non si possono usare cicli se non durante l’acquisizione dei parametri
    (e.g., dimensione dell’array e sequenza)*/

    if (*arr == *(arr + dim))
    {
        if (dim <= 1)
        {
            return true;
        }
        return Due(arr + 1, dim - 2);
    }
    else
    {
        return false;
    }
}

bool Tre(int text[], int pat[], int dim, int dimPat)
{
    /*Scrivere un programma che verifichi se un array di interi “pattern” è
    contenuto in un altro array di interi “testo”. Generare randomicamente i
    due array (è concesso l’uso della funzione rand() nella libreria
    <cstdlib>) con una dimensione fissata a priori (massimo 100).*/

    int i = 0;
    while (i < dim)
    {
        bool found = true;
        for (int j = 0; j < dimPat; j++)
        {
            if (text[i + j] != pat[j])
            {
                found = false;
                break;
            }
        }

        if (found)
            return true;
        else
            i++;
    }

    return false;
}

int *Quattro(int N, int *arr = nullptr)
{
    /*Scrivere un programma che, dato un intero positivo N, crei
    dinamicamente e stampi un array contenente i primi N numeri
    esagonali, partendo da 0.
    L’i-esimo numero esagonale è uguale a

    Esagonale(i) = i*(2*i-1)

    Nota: non si possono usare cicli*/

    if (arr == nullptr)
    {
        arr = new int[N];
    }

    if (N == 0)
        return arr;

    arr[(N - 1)] = (N - 1) * (2 * (N - 1) - 1);
    Quattro((N - 1), arr);
    cout << arr[(N - 1)] << endl;
    return arr;
}

void Cinque(int row, int col)
{
    int **mat = Random_Mat(row, col, 1, 10);
    /*Scrivere un programma che, dati due interi in input (righe e colonne), crei
    dinamicamente una matrice e la riempia con valori interi random (è concesso
    l’uso della funzione rand() nella libreria <cstdlib>).

    In seguito, chiedere all’utente le dimensioni della sottomatrice da stampare.
    Le dimensioni sono fornite tramite quattro numeri, corrispondenti alle coordinate del primo
    elemento (2 numeri) e alle dimensioni della sottomatrice (numero di righe e
    colonne).

    Se le dimensioni fornite dall’utente eccedono quelle della matrice,
    stampare la sottomatrice massima disponibile.

    Deallocare infine la matrice.*/

    Print_Mat(mat, row, col);

    int r, c, nr, nc;

    /*
    dim 4

        0 1 2 3
        | | | |
    0 - 1 2 3 4
    1 - 4 3 2 1
    2 - 1 2 3 4
    3 - 4 3 2 1
    */

    r = Input_Utl<int>((char *)"Inserisci la riga del num: ");
    c = Input_Utl<int>((char *)"Inserisci la colonna del num: ");
    nr = Input_Utl<int>((char *)"Inserisci il numero di righe: ");
    nc = Input_Utl<int>((char *)"Inserisci il numero di colonne: ");

    r = (r < 0 ? 0 : r);
    r = r >= row ? row - 1 : r;
    c = (c < 0 ? 0 : c);
    c = c >= col ? col - 1 : c;
    nr = nr >= row - r ? row - r : nr;
    nc = nc >= col - c ? col - c : nc;

    for (int i = r; i < (r + nr); i++)
    {
        for (int j = c; j < (c + nc); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Sei(char v[], int n)
{
    /*Scrivere un programma che, dato un vettore v di dimensione 5
    contenente caratteri maiuscoli definiti a tempo di compilazione, chieda
    in input un intero positivo j e stampi un nuovo vettore ottenuto dalla
    rotazione a sinistra di j posizioni del contenuto del vettore v

    Opzionale: la funzione di ruota array deve avere una complessità O(n)
    (niente cicli annidati)*/

    char *arr = Copy_Arr(v, 5);

    for (int i = 0; i < 5; i++)
        v[i] = arr[(i + n) % 5];

    Print_Arr(v, 5);
}

void Sette(char file[])
{
    fstream f = OpenFile_Utl(file, ios::in);

    int med = 0;
    int ctr = 1;
    char c;
    bool stop = false;

    c = f.get();
    while (c != EOF)
    {
        if (c != '*')
        {
            if (!stop)
            {
                ctr++;
                stop = true;
            }
        }
        else
        {
            stop = false;
            med++;
        }
        c = f.get();
    }
    med /= ctr;

    f = OpenFile_Utl(file, ios::app);

    char *arr = new char[med + 1];
    arr[0] = '\n';
    for (int i = 1; i < (med + 1); i++)
    {
        arr[i] = '*';
    }

    f.write(arr, med + 1);
    f.close();
}

void Otto()
{
    /*Scrivere un programma che, presi i nomi di due file da linea di
    comando, copi il primo file nel secondo correggendone la sintassi.

    Affinché un testo possa essere considerato corretto, la prima parola del
    testo e tutte le parole dopo i caratteri “.”, “?” e “!” devono iniziare con
    una lettera maiuscola.

    Potete usare la libreria <fstream>.

    Inoltre potete scrivere “input >> noskipws;” per impedire
    all’operatore “>>” di skippare spazi bianchi e nuove linee*/

    fstream in = OpenFile_Utl("../input.txt", ios::in);
    fstream out = OpenFile_Utl("../output.txt", ios::out);

    char c;
    bool upp = true;

    c = in.get();

    while (c != EOF)
    {
        if (('a' <= c && c <= 'z') && upp)
        {
            c -= 32;
            upp = false;
        }
        else if (c == '.' || c == '?' || c == '!')
        {
            upp = true;
        }

        out.put(c);
        c = in.get();
    }

    in.close();
    out.close();
}

int main()
{
    Otto();

    return 0;
}