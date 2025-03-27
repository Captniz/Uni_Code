#include "Pila_class.h"

Pila_class::Pila_class(int initialSize) {
    std::cout << "entro in crea" << std::endl;
    size = initialSize;
    marker = 0;
    contenuto = new int[initialSize];
}
//Pila_class::~Pila_class() {
//    std::cout << "entro in distruggi" << std::endl;
//    delete[](contenuto);
//}
bool Pila_class::piena(){
    return size == marker;
}
void Pila_class::cresci(int increment){
    std::cout << "entro in cresci" << std::endl;
    size += increment;
    int* temp = new int[size];
    for(int k=0; k < marker; k++){
        temp[k] = contenuto[k];
    }
    delete[](contenuto);
    contenuto = temp;
}
void Pila_class::inserisci(int k){
    std::cout << "entro in inserisci" << std::endl;
    if (this->piena()){
        this->cresci(this->defaultGrowthSize);
    }
    contenuto[marker] = k;
    marker++;
}
int Pila_class::estrai(){
    std::cout << "entro in estrai" << std::endl;
    assert(marker>0);
    int indx = marker;
    marker--;
    return contenuto[indx];
//    return s->contenuto[--(s->marker)];
}
void Pila_class::stampastato(){
    std::cout << "==================" << std::endl;
    std::cout << "size =" << size << std::endl;
    std::cout << "marker =" << marker << std::endl;
    for(int k=0; k<marker; k++){
        std::cout << "[" << contenuto[k] << "]" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "==================" << std::endl;
}
Pila_class* Pila_class::copia(){
    std::cout << "entro in copia" << std::endl;
    Pila_class* to = new Pila_class(this->size);
    for(int k=0; k< marker; k++){
        to->contenuto[k] = contenuto[k];
    }
    to->marker = marker;
    return to;
}
