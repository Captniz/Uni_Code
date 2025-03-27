package Lecture_03;
// classes, objects
// semantic language design

import Lecture_07.Orange;

public class Lecture_03 {
    // valutiamo alcune delle differenze sintattiche per poi
    // parlare delle differenze sostanziali dovute al paradigma OO
    public static void main(String[] args){
        // SLIDE: che tipi ha Java (no unsigned)
        // primitivi
        // riferimento: user-defined: classi (e interfacce) + array
        // non ci sono structs (le classi son gia simili)
        allocazione_Array();

        // replichiamo il main del C++ in Java
        pila();

        // SLIDE: metodi e attirbuti di classe
        // Come posso avere classi e oggetti globali?
        // guardiamo alla StaticClass
        explain_statics();

        enums();

    }

    private static void allocazione_Array(){
        // SLIDE: tipi array
        // SLIDE:  allocazione di memoria

        // SLIDE array di oggetti: definizione
        // creiamo un array di persone (nelle slides, arrp si chiama person)
        Persona[] arrp;
        // MENTIMETER: Dato che Persona[] e` un tipo puntatore, che valore ha arrp ora?

        // SLIDE
        // la riga di sotto fa la malloc
        arrp = new Persona[20];
        // SLIDE+DRAW memory layout
        //
        arrp[0] = new Persona("Marco");
        // DRAW memory layout
        arrp[0] = new Persona("Lorenzo");
        // SLIDE array obj VS array base
        int[] arrint = new int[10];
    }
    // back to main

    private static void pila(){
        // questo codice e` come quello in C++, modulo sintassi di Java
        // differenza tra sintassi dei linguaggi, e la loro semantica
        // cosa scriviamo VS come si comporta il linguaggio?
        // lo vedete anche in FP: il comportamento e` diverso da C/Java

        // SLIDE pila in java
        // apriamo pila.java

        Pila s = new Pila(5);
        System.out.print("s");
//        System.err.println();
        s.stampastato();
        for(int k=1; k<10; k++){
            s.inserisci(k);
        }
        System.out.print("s");
        s.stampastato();
        Pila w = s.copia();
        System.out.print("w");
        w.stampastato();
        for (int k=0; k<8 ; k++) {
            System.out.println(s.estrai());
        }
        System.out.print("s");
        s.stampastato();

        for(int k=0; k<15; k++){
            System.out.println(w.estrai());
        }
        System.out.print("w");
        w.stampastato();

        // back to main
    }

    private static void explain_statics(){
        C_s a = new C_s();
        C_s b = new C_s();
        // il codice nella slide e` 'incorretto',
        //  IntelliJ non ce lo consiglia neanche deve fare C.x
        a.a_static_method(new Persona("pino")); // da commentare
        // SLIDE: attributi di classe: condivisione. gli statics sono condivisi
        // DRAW: memory layout of a, b and their classes
        C_s.x_static_int =5;
        a.y_nonstatic_int = 1;
        b.y_nonstatic_int = C_s.x_static_int + 2;
        // MENTIMETER quanto vale b.y_... ?
        // e se x_static non fosse static?

        System.out.println();

        //=== start

        // MENTIMETER cosa e` static in System.out.println()
        // apriamo la javadoc

        // DRAW: memory layout of a, b and their classes

        // SLIDE: metodi di classe: vincoli:
        //  dall'istanza accedo a static. da static accedo solo a static
        //  differenza tra cosa e` creato a runtime (istanze)
        //  e cosa a start-time (classi, cose statiche)

        // apriamo la classe Shape
        // torniamo alla Pila ->inserisci
    }


    // SLIDE enums
    // il codice qui sotto definisce dei MAGIC NUMBERS
    // non e` buona prassi, porta un sacco di errori,
    // quindi usiamo una enum
    //  enums in java sono opache
    //  enum == final class (inserito dal compilatore)
    public static final int APPLE_FUJI = 0;
    public static final int APPLE_PIPPIN = 1;
    public static final int APPLE_GRANNY_SMITH = 2;
    public static final int ORANGE_NAVEL = 0;
    public static final int ORANGE_TEMPLE = 1;
    public static final int ORANGE_BLOOD = 2;
    private static void enums() {
        // apriamo la enum Apple
        Apple a = Apple.FUJI;
        // apriamo la enum Orange
        // back
        Orange o = Orange.TEMPLE;
        o.a();
    }
}
