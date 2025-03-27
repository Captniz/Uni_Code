package Lecture_04;

// cos'e` questo?  serve per dire a Java dove trovare la classe Pila
import Lecture_03.Pila;

public class Coda extends Pila {

    // SLIDE cambiamo come si estrae dalla Coda
    // si chiama Overriding -- riscrizione
    public int estrai() {
        // SLIDE: modificatori di accesso, come accedo a marker qui?
        assert(marker>0);
        int retval = contenuto[0];
        for(int k=1; k<marker; k++){
            contenuto[k-1] = contenuto[k];
        }
        marker--;
        return retval;
        // e il resto del codice? inserisci, marker, etc .. ?
        // notare la keyword 'extends' nella definizione della Class
        // che definisce la relazione tra Coda e Pila nella gerarchia di ereditarieta`
        // SLIDE - DRAW : gerarchia di ereditarieta`
        // SLIDE: classe object
        // back to main
    }

    // questo lo vediamo dopo
    public Coda(int size){
        // chiamata al costruttore di Pila
        super(size);
    }

    // back to main
}
