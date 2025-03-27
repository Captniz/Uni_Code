package Lecture_04;

import Lecture_03.Pila;

public class Lecture_04 {
    // MENTIMETER: policy di accesso di Pila e Coda
    public static void main(String[] args){
        coda();
        // SLIDE: overriding: vedere l'esempio dell'automobile

        // SLIDE: overriding: Point
        // SLIDE: subclassing e overriding
        points();

        // SLIDE: ereditarieta`-> Costruttore di Coda
        // MENTIMETER: compilano ?

        // SLIDE: overloading
        overloading();

        // SLIDE: ES per casa
    }

    private static void coda() {
        // creiamo una coda
        // vediamo la classe coda brevemente
        Coda s = new Coda(5);
        // dov'e` questo metodo?
        s.stampastato();
        for(int k=1; k<10; k++){
            // e questo ?
            s.inserisci(k);
        }
        System.out.print("s");
        s.stampastato();
        for (int k=0; k<8 ; k++) {
            // e questo (estrai)?
            System.out.println(s.estrai());
        }
        // SLIDE - DRAW: memory layout di Coda e Pila
        // SLIDE: Ereditarieta`: cosa possiamo fare quando facciamo extend?
        //back
    }

    private static void points() {
        // SLIDES (3 slides)
        Point p = new Point(5,3);
        System.out.println(p);
        NamedPoint pp = new NamedPoint(5,3,"A");
        System.out.println(pp);
        // back
    }

    private static void overloading(){
        Overloader o = new Overloader();
        System.out.println(o.f());
        System.out.println(o.f(10));
        // decommentare quella di void, come la distinguo?

        // SLIDE: overload VS override
        // back
    }
}
