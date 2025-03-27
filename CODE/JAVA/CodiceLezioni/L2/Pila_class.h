#include <iostream>

// una delle differenze tra classe e struct sta nella visibilita` di default
class Pila_class {
//    private by default
    int size;
    int marker;
    int* contenuto;
    int defaultGrowthSize = 10;
public:
    void cresci(int increment);
    Pila_class(int initialSize);
    void distruggi();
    bool piena();
    void inserisci(int k);
    int estrai();
    void stampastato();
    Pila_class* copia();
};


struct Pila_struct {
//    public by default
    int size;
    int defaultGrowthSize;
    int marker;
    int* contenuto;
private:
    void cresci(int increment);
    Pila_struct(int initialSize);
    void distruggi();
    bool piena();
    void inserisci(int k);
    int estrai();
    void stampastato();
    Pila_struct* copia();
};
