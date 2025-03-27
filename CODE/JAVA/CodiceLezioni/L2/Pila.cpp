#include <iostream>
#include <cassert>
#include "Pila.h"

// spieghiamo le varie funzioni
Pila* crea(int initialSize) {
    std::cout << "entro in crea" << std::endl;
    // new: operatore per allocare sullo heap "simile" a malloc
    Pila* s = new Pila ;
    // a->b significa  (*a).b
    s->size = initialSize;
    s->marker = 0;
    s->contenuto = new int[s->size];
    return s;
}
void distruggi(Pila* s){
    std::cout << "entro in distruggi" << std::endl;
    // delete: operatore per deallocare "simile" a free
    delete[](s->contenuto);
    delete s;
}
bool piena(Pila* s){
    return s->size == s->marker;
}
void cresci(Pila* s, int increment){
    std::cout << "entro in cresci" << std::endl;
    s->size += increment;
    int* temp = new int[s->size];
    for(int k=0; k < s->marker; k++){
        temp[k] = s->contenuto[k];
    }
    delete[](s->contenuto);
    s->contenuto = temp;
}
void inserisci(Pila* s, int k){
    std::cout << "entro in inserisci" << std::endl;
    const int growthSize = 5;
    if (piena(s)){
        cresci(s,growthSize);
    }
    s->contenuto[s->marker] = k;
    s->marker++;
}
int estrai(Pila* s){
    std::cout << "entro in estrai" << std::endl;
    assert(s->marker>0);
    int indx = s->marker;
    s->marker--;
    return s->contenuto[indx];
//    return s->contenuto[--(s->marker)];
}
void stampastato(Pila* s){
    std::cout << "==================" << std::endl;
    std::cout << "size =" << s->size << std::endl;
    std::cout << "marker =" << s->marker << std::endl;
    for(int k=0; k<s->marker; k++){
        std::cout << "[" << s->contenuto[k] << "]" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "==================" << std::endl;
}
Pila* copia(Pila* from){
    std::cout << "entro in copia" << std::endl;
    Pila* to = crea(from->size);
    for(int k=0; k< from->marker; k++){
        to->contenuto[k] = from->contenuto[k];
    }
    to->marker = from->marker;
    return to;
}

// torniamo al main per vedere come funziona