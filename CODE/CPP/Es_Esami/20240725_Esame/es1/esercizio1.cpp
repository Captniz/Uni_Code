// Allowed include
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

// Add your code hereafter

using namespace std;

int ContaParole(char *arr[]);
void GeneraParole(char *pwords[], int num, char (&arr)[7]);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    fstream in = fstream(argv[1], ios::in);
    if (!in.is_open())
    {
        cout << "Errore, file non trovato";
        return 1;
    }

    char text[5000];
    char *pwords[5000];
    for (int i = 0; i < 5000; i++)
        pwords[i] = NULL;

    char c;
    int ctr_text = 0;
    int ctr_pwords = 0;
    bool new_word = true;
    while (in.get(c))
    {
        text[ctr_text] = c;

        if (c == '\n' || c == ' ')
            new_word = true;

        if (new_word && ((c >= 'a' && c <= 'z') || ((c >= 'A' && c <= 'Z'))))
        {
            pwords[ctr_pwords] = &text[ctr_text];
            ctr_pwords++;
            new_word = false;
        }

        ctr_text++;
    }

    cout << "Text: " << endl;
    for (int i = 0; i < ctr_text; i++)
        cout << text[i];

    cout << endl
         << endl
         << "Number of words: " << ContaParole(pwords) << endl;

    cout << "Initials: ";

    for (int i = 0; i < ctr_pwords; i++)
        cout << *pwords[i];

    char word[7];
    GeneraParole(pwords, ContaParole(pwords), word);

    cout << endl
         << "Generated word:" << word;

    in.close();
    return 0;
}

int ContaParole(char *arr[])
{
    int ctr = 0;
    while (arr[ctr] != NULL)
        ctr++;

    return ctr;
}

void GeneraParole(char *pwords[], int num, char (&arr)[7])
{
    srand(time(NULL));

    for (int i = 0; i < 6; i++)
        arr[i] = *pwords[(rand() % (num))];

    arr[6] = '\0';

    return;
}