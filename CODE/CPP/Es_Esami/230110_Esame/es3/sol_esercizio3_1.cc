#include <iostream>
#include "pila.h"

using namespace std;

int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti);

int main() {
    
    // Potete modificare l'array di asteroidi (e la sua
    // dimensione) per testare la vostra soluzione
    int asteroidi [] = {11, -5, -12, 4, -6};
    int numeroAsteroidi = 5;


    int numeroAsteroidiRimasti;
    int * asteroidiRimasti = collidiAsteroidi(asteroidi, numeroAsteroidi, numeroAsteroidiRimasti);


    // La stampa dell'array dinamico degli
    // asteroidi rimasti avviene nel main
    for (int i = 0; i < numeroAsteroidiRimasti ; i++) {
        cout << asteroidiRimasti[i] << " ";
    }
    cout << endl;

    // La deallocazione dell'array dinamico 
    // degli asteroidi rimasti avviene nel main
    delete[] asteroidiRimasti;
}


// Implementare la funzione sottostante come da consegna:
// - ritornare un'array di interi allocato dinamicamente che 
//   contenga lo stato degli asteroidi dopo tutte le collisioni
// - assegnare a 'numeroAsteroidiRimasti' il numero di elementi 
//   nell'array ritornato
int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti) {
    
    init();

    numeroAsteroidiRimasti = numeroAsteroidi;
    int asteroidePila;

    for (int i = 0 ; i < numeroAsteroidi ; i++) {
        int asteroideCorrente = asteroidi[i];
        if (asteroideCorrente > 0 || vuota()) {
            push(asteroideCorrente);
        } else {
            asteroideCorrente = -asteroideCorrente;
            top(asteroidePila);

            // Distruggiamo tutti gli asteroidi 
            // più piccoli che si muovono a destra
            while(!vuota() && asteroidePila > 0 && asteroidePila < asteroideCorrente) {
                numeroAsteroidiRimasti--;
                pop();
                top(asteroidePila);
            }

            // Distruzione di entrambi gli asteroidi
            if (!vuota() && asteroidePila == asteroideCorrente) {
                pop();
                numeroAsteroidiRimasti -= 2;
            } else {
                if (vuota() || asteroidePila < 0) {
                    push(-asteroideCorrente);
                } else {
                    // L'asteroide che si muoveva a sinistra 
                    // viene distrutto da un asteroide più grande
                    numeroAsteroidiRimasti--;
                }
            }
        }
    }

    // Riversiamo la coda nell'array da ritornare
    int temp = numeroAsteroidiRimasti;
    int * asteroidiRimasti = new int[temp];
    while (top(asteroidePila)) {
        temp--;
        asteroidiRimasti[temp] = asteroidePila;
        pop();
    }

    deinit();


    return asteroidiRimasti;
}





