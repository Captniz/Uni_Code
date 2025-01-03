#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

// E' possibile avere delle funzioni di appoggio per la codifica delle parole in numeri e viceversa.
// Ad esempio:
// int encode(char * decoded);
// void decode(int coded, char * decoded);

int main(int argc, char *argv[])
{

  // inserire qui il codice

  fstream in = fstream(argv[1], ios::in);
  fstream out = fstream(argv[2], ios::out);
  if (!in.is_open() || !out.is_open())
  {
    cout << "Errore nell'apertura del file" << endl;
    return 1;
  }

  int key;
  do
  {
    cout << "Inserire la chiave di cifratura: ";
    cin >> key;
  } while (key > 9999999 || key < 0);

  char word[50];
  while (!in.eof())
  {
    in >> word;

    int decode = 0;
    int ctr = 0;

    while (ctr < 4 && word[ctr] != '\0')
    {
      int val = 0;

      if (word[ctr] <= 'z' && word[ctr] >= 'a')
        val = word[ctr] - 87;
      else
        val = word[ctr] - 48;

      cout << val << " " << pow(36, 3 - ctr)<<endl;
      decode += val * pow(36, 3 - ctr);
      ctr++;
    }
    // decode += key;
    cout << decode;
  }

  return 0;
}
