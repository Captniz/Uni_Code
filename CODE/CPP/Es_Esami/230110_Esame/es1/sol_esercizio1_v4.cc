#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;

// Costanti
const int MAX_LENGTH = 8;



int encode(char * numero) {

  int base = 1;
  int risultato = 0;

  // Iniziamo dal numero meno significativo (unità) e scorriamo
  // in avanti nell'array.
  for (int i=strlen(numero)-1; i>=0; i--) {

    if (numero[i] == '0') {
      risultato += 0*base;

    } else if (numero[i] >= 'a' && numero[i] <= 'z') {

      // Se il valore non è un numero, allora dobbiamo convertire
      // la lettera nel suo corrispondente valore intero.
      int valore = 1 + (numero[i]-'a');
      risultato += valore*base;

    }

    // Ad ogni iterazione, incremento la base. Questo equivale a scrivere
    // b^i nella sommatoria.
    base = base * 27;
  }

  return risultato;

}



void decode(int coded, char * decoded) {

  int i = 0;

  while (coded != 0) {
    int modulo = coded % 27;
    coded =  ( coded - modulo ) / 27;

    if (modulo==0) {
      decoded[i] = '0';
    }
    else {
      decoded[i] = 'a'-1 + modulo;
    }
    i++;
  }
  decoded[i] = '\0';

  // cout << " -> reversed " << decoded;
  
  // reverse string
  for (int j=0; j<i/2; j++) {
    char tmp = decoded[j];
    decoded[j] = decoded[i-1-j];
    decoded[i-1-j] = tmp;
  }

}


int main(int argc, char * argv []) {

  // Controllo che gli argomenti ci siano tutti
  if (argc != 3) {
    cout << "Usage: exercise1.out <input> <output>" << endl;
    exit(1);
  }

  // Apro gli stream di lettura e scrittura
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  // Controllo che gli stream siano stati aperti correttamente
  if (input.fail() || output.fail()) {
    cout << "Errore nell'apertura degli stream!" << endl;
  }

  cout << "Questo programma codifica un testo parola per parola , sommando la chiave di codifica alla parola." << endl
  << "Le parole sono decodificate come numeri in base 27, dieci cifre 0...9 e ventisei caratteri a...z." << endl
  << "Dove "
  << "0->" << 0
  << ", "
  << "a->" << 1 // a->1
  << ", "
  << "z->" << 1 + 'z' - 'a' // z->26
  << ", "
  << "a0->" << 1*pow(27,1) + ( 0*pow(27,0) ) // a0->27
  << ", "
  << "az->" << 1*pow(27,1) + ( 26*pow(27,0) ) // az->53
  << ", "
  << "b0->" << 2*pow(27,1) + ( 0*pow(27,0) ) // b0->54
  << endl;
  
  // Creo il buffer per la lettura
  char buffer[MAX_LENGTH];

  int key = 1;
  while (true) {
    cout << "Inserire un numero da usare come chiave di criptatura (massimo 7 cifre): ";
    cin >> buffer;
    if ( strlen(buffer) <= 5 )
      break;
  }
  key = atoi(buffer);
  cout << key << endl;

  while(input >> buffer) {

    cout << buffer;
    buffer[3] = '\0';

    int encoded;

    encoded = encode(buffer);
    cout << " (" << encoded << ") ";

    encoded += key;
    decode(encoded, buffer);
    cout <<" -> crypted " << buffer << " (" << encoded << ") ";
    output << buffer << " ";

    encoded = encode(buffer) - key;
    decode(encoded, buffer);
    cout << " -> decrypted " << buffer  << " (" << encoded << ") " << endl;

  }

  input.close();
  output.close();

  return 0;

}
