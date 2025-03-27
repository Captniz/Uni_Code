struct Pila_es {
    int size;
    int marker;
    int* contenuto;
    // spostiamo estrai dentro a Pila
    int estrai_e();
};
// il resto e` uguale
Pila_es* crea_e(int initialSize);
void distruggi_e(Pila_es* s);
bool piena_e(Pila_es* s);
void cresci_e(Pila_es* s, int increment);
void inserisci_e(Pila_es* s, int k);
//int estrai(Pila_es* s);
void stampastato_e(Pila_es* s);
Pila_es* copia_e(Pila_es* from);