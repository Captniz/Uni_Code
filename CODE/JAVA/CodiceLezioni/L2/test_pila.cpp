#include "Pila.cpp"
#include "Pila_estrai.cpp"
#include "Pila_class.cpp"

// OBIETTIVO: programmare una pila in C++, capirene i limiti, applicare OO per superare i limiti
void test_pila(){
    // vediamo di costruire una Pila: Pila.h
    // e torniamo qui dopo averne capito le funzionalita` che sono in Pila.cpp
    Pila* s = crea(5);
    std::cout << "s" ;
    stampastato(s);
    for(int k=1; k<10; k++){
        inserisci(s,k);
    }
    std::cout << "s" ;
    stampastato(s);
    Pila *w = copia(s);
    // MENTIMETER: cosa succede se facciamo
    //  Pila *w = s;
    std::cout << "w" ;
    stampastato(w);
    for (int k=0; k<8 ; k++) {
        std::cout << estrai(s) << std::endl ;
    }
    std::cout << "s" ;
    stampastato(s);
    distruggi(s);
    //    std::cout << "s" ;
    //    stampastato(s);
    for(int k=0; k<15; k++){
        std::cout << estrai(w) << std::endl ;
    }
    std::cout << "w" ;
    stampastato(w);
    // MENTIMETER: funziona?
}
// SLIDES: problemi interfaccia-implementazione

// vediamo Pila_estrai.h
int test_pila_e(){
    // vediamo l'utilizzo del tipo Pila_es, preso da Pila_estrai.cpp
    Pila_es* e = crea_e(5);
    std::cout << "e" ;
    stampastato_e(e);
    for(int k=1; k<10; k++){
        inserisci_e(e,k);
    }
    std::cout << "e" ;
    stampastato_e(e);
    for (int k=0; k<8 ; k++) {
        // cambia il modo in cui usiamo estrai
        std::cout << e->estrai_e() << std::endl ;
    }
    std::cout << "e" ;
    stampastato_e(e);
    return 0;
}
// SLIDES: problemi incapsulamento e information hiding
//
// vediamo Pila_class.h

void test_pila_class(){

    // notate il cambiamento, abbiamo un costruttore
    Pila_class* s = new Pila_class(5);
    std::cout << "s" ;
    // notate che tutti i metodi si chiamano cosi`
    // cos'e` un metodo? ne diamo la definizione formale nella prossima lezione
    s->stampastato();
    for(int k=1; k<10; k++){
        s->inserisci(k);
    }
    std::cout << "s" ;
    s->stampastato();
    Pila_class *w = s->copia();
    std::cout << "w" ;
    w->stampastato();
    for (int k=0; k<3 ; k++) {
        std::cout << s->estrai() << std::endl ;
    }
    std::cout << "s" ;
    s->stampastato();
    // MENTIMETER: posso accedere al campo marker di s?

    // quanto vale marker?
    // breve intromissione: sicurezza, e l'importanza dei linguaggi
    int* pp = (int*) s;
    std::cout << "pp: " << *pp ;    // s.size
    pp++;
    std::cout << "pp: " << *pp ;    // s.marker
    pp++;
    std::cout << "pp: " << *pp ;    // some pointer A
    pp++;
    std::cout << "pp: " << *pp ;    // some pointer B
    pp++;
    std::cout << "pp: " << *pp ;    // def.
    pp++;
    std::cout << "pp: " << *pp ;    // 0
    pp++;
    std::cout << "pp: " << *pp ;    // 0
    pp++;
    std::cout << "pp: " << *pp ;    // 0
    pp++;
    std::cout << "pp: " << *pp ;    // w.size!
    pp++;
    std::cout << "pp: " << *pp ;    // w.marker!
    pp++;
    std::cout << "pp: " << *pp ;    // some pointer C
    pp++;
    std::cout << "pp: " << *pp ;    // B again!
    pp++;

    // notate il cambio per deallocare s
    delete s;
}