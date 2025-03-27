package Lecture_06;

import Lecture_04.AutomobileElettrica;
import Lecture_04.Automobile;

public class Lecture_06 {
    // SLIDE: metodi final
    public static void main(String[] args){
        // andiamo dentro la classe Test

        //SLIDE override di metodi statici
        Esercizio1CD.esercizio();

        System.out.println("--------------");
        //SLIDE: pila polimorfica
        pila();

        // SLIDE esempio upcasting e downcasting

        casting();

        // SLIDE esercizio
        Esercizio2AB.esercizio();

        System.out.println("--------------");
        // SLIDE: instanceof
        pila2();

        // SLIDE: problemi con l'ereditarieta` semplice
        // SLIDE: ereditarieta` multipla
        // SLIDE: soluzione Java
        // le interfacce contengono firme e default methods TODO (ma sono interfacce o traits?)
        // le interfacce possono estendere piu` interfacce
        // le classi possono implementare (new keyword: implements) piu` interfacce
        // vediamo AccessoDati, VettoreDati e Insieme

        // SLIDE: problama: una gerarchia multidimensionale
        // non si schiaccia in una gerarchia mododimensionale ad albero

        // SLIDE: polimorfismo e interfacce
        // come le classi, le interfacce sono TIPI
        AccessoDati o = new Pila(10);
        o.inserisci(5);
        // AccessoDati o = new AccessoDati();
        // SLIDE: esercizio
        EsercizioAnimali.esercizio();
        // SLIDE: ereditarieta`, polimorfismo e array
        array_poly();
    }

    public static void pila(){
        int dim = 10;
        // vediamo come possiamo usare final in VettoreDati
        // e come possiamo cambiare VettoreDati per contenere cose "diverse"
        Pila s = new Pila(dim);
        for(int k=0; k<dim; k++){
            // questo funziona, ma a causa dell'auto-boxing
            // SLIDE: classi wrapper + codice di Pila Polimorfa
            // SLIDE: conversioni automatiche: autoboxing: casting automatico da int a Integer
            s.inserisci(k);
        }
        for (int k=0; k<8; k++) {
            // qui pero` il casting e` necessario
            // SLIDE: casting
            int w = (Integer) s.estrai();
            System.out.println(w);
        }
        //back
    }

    public static void casting(){
        // casting: conversione di tipo
        // upcasting: conversione implicita dovuta al polimorfismo
        // downcasting: conversione __esplicita__ :
        //      se castiamo un oggetto  o  di tipo T verso T1
        //      funziona solo se il tipo dinamico di  o   e` un sottotipo di T1

        Object o = new AutomobileElettrica();
//        Automobile a = o; // errato, Object non è un sottotipo di Automobile
        Automobile a = (Automobile) o; // corretto (casting)
        // back
    }

    public static void pila2(){
        int dim=10;
        Pila s = new Pila(dim);
        // inserimento valori
        for(int k=0; k<dim; k++) {
            Object o;
            // scegliamo di inserire cose a caso, il tipo del contenuto ce lo permette!
            if (Math.random()<0.5){
                o = new Integer(k);
            }
            else {
                o = new Float(k * Math.PI);
            }
            s.inserisci(o);
        }
        // e quando dobbiamo leggere?
        // instanceof ci previene errori dovuti al downcast
        for(int k=0; k<dim; k++) {
            // prima salviamo dentro il tipo corretto : Object
            Object o = s.estrai();
            // poi controlliamo il tipo dinamico con instanceof
            if (o instanceof Integer) {
                // poi facciamo il cast
                Integer i = (Integer) o;
                int w = i.intValue();
                System.out.println("an int:" + w);
            } else if (o instanceof Float) {
                // poi facciamo il cast
                Float i = (Float) o;
                float w = i.floatValue();
                System.out.println("a float:" + w);
            } else
                System.out.println("Unknown class!");
        }
    }


    private static void array_poly() {
        Lecture_06 l = new Lecture_06();
        // non funziona, non e` type-safe
        // l.f(new Y[10]);
        // TODO
    }
    private void f (X[] ax) {
        ax[0] = new X();
    }
    class X{}
    class Y extends X{}
}
