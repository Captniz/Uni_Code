// definizione della struttura dati e delle funzioni che le appartengono
struct Pila {
    int size;
    int marker;
    // le annotazioni di tipo hanno un significato anche per gli umani
    int* contenuto;
};
Pila* crea(int initialSize);
void distruggi(Pila* s);
bool piena(Pila* s);
void cresci(Pila* s, int increment);
void inserisci(Pila* s, int k);
int estrai(Pila* s);
void stampastato(Pila* s);
Pila* copia(Pila* from);

// implementazione in Pila.cpp