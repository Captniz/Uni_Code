#include <iostream>
#include <cassert>
#include "Pila_estrai.h"

// qualifichiamo estrai che appartiante a Pila prima del nome
int Pila_es::estrai_e(){
    std::cout << "entro in estrai" << std::endl;
    assert(this->marker>0);
    int indx = this->marker;
    this->marker--;
    return this->contenuto[indx];
//    return s->contenuto[--(s->marker)];
}

// il resto e` invariato
Pila_es* crea_e(int initialSize) {
    std::cout << "entro in crea" << std::endl;
    Pila_es* s = new Pila_es ;
    s->size = initialSize;
    s->marker = 0;
    s->contenuto = new int[s->size];
    return s;
}
void distruggi_e(Pila_es* s){
    std::cout << "entro in distruggi" << std::endl;
    delete[](s->contenuto);
    delete s;
}
bool piena_e(Pila_es* s){
    return s->size == s->marker;
}
void cresci_e(Pila_es* s, int increment){
    std::cout << "entro in cresci" << std::endl;
    s->size += increment;
    int* temp = new int[s->size];
    for(int k=0; k < s->marker; k++){
        temp[k] = s->contenuto[k];
    }
    delete[](s->contenuto);
    s->contenuto = temp;
}
void inserisci_e(Pila_es* s, int k){
    std::cout << "entro in inserisci" << std::endl;
    const int growthSize = 5;
    if (piena_e(s)){
        cresci_e(s,growthSize);
    }
    s->contenuto[s->marker] = k;
    s->marker++;
}
void stampastato_e(Pila_es* s){
    std::cout << "==================" << std::endl;
    std::cout << "size =" << s->size << std::endl;
    std::cout << "marker =" << s->marker << std::endl;
    for(int k=0; k<s->marker; k++){
        std::cout << "[" << s->contenuto[k] << "]" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "==================" << std::endl;
}
Pila_es* copia_e(Pila_es* from){
    std::cout << "entro in copia" << std::endl;
    Pila_es* to = crea_e(from->size);
    for(int k=0; k< from->marker; k++){
        to->contenuto[k] = from->contenuto[k];
    }
    to->marker = from->marker;
    return to;
}
