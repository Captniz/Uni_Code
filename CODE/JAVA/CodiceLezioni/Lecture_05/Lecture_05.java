package Lecture_05;

import Lecture_03.Persona;
import Lecture_04.Automobile;
import Lecture_04.AutomobileElettrica;
import Lecture_04.NamedPoint;
import Lecture_04.Point;

public class Lecture_05 {

    public static void main(String[] args){
        // Risoluzione esercizio di 2 settimane fa
        // MENTIMETER 3x
        // DRAW memory layout (stack + heap)

        // classi astratte
//        abstracts();

        // esempi di polimorfismo coi punti
//        poly_points();
        // esempi di polimorfismo con le auto
//        poly_auto();

        // un concetto legato al subtyping polymorphism e` il dynamic binding
        dynamic_binding();
        // esempi di dynamic binding con persona
//        dynb_persona();
        // esempio

        // MENTIMETER: - SLIDE - esercizio
//        Esercizio1ABC.esercizio(); // + variazione
        // esempio
//        Esercizio2AB.esercizio();
        // esempio
//        Esercizio3CD.esercizio();
        // SLIDE: static e dynamic binding in c, java (rust)
    }

    private static void abstracts() {
        // SLIDE: classi e metodi astratti
        // vediamo VettoreDati

        // creare VettoreDati non ha molto senso
        VettoreDati v = new VettoreDati() {
            @Override
            public int estrai() { return 0; }
        };
        // SLIDE - DRAW: memory layout
        // pero` possiamo fare questo

        Pila p = new Pila();
        VettoreDati vdp = new Pila();
        Coda c = new Coda();
        VettoreDati vdc = new Coda();

        VettoreDati[] vvv = {vdp,vdc,p};
        asd(c);
        c.iscoda();
        asd(p); asd(vdp);
        vdp.estrai();

        // cosa succede?
        // SLIDES (4): polimorfismo
        // il polimorfismo di sottotipo si applica alle definizioni
        // perche`  Pila <: VettoreDati
        // <:  si legge: "e` sottotipo di "

        // DRAW: memory layout, perche` il polimorfismo di sottotipo ha senso
        //  estensione di funzionalita` (cos'e` una classe?)

        // MENTIMETER :sono corrette?
        // back
    }
    private static void asd(VettoreDati v){
        v.stampastato();
    }

    private static void poly_points() {
        // SLIDEs
        Point p = new Point(1,2);
        p.move(3,4);
        p = new NamedPoint(5,7,"A");
        p.move(3,4);
        // creiamo una Line, che ha 2 punti
        Point p1 = new Point(1,2);
        NamedPoint p2 = new NamedPoint(5,7,"A");
        Line l = new Line(p1, p2);
        // MENTIMETER: che polimorfismo sto usando?
        // back
    }

    private static void poly_auto() {
        // creiamo un parcheggio per auto
        Parcheggio p = new Parcheggio(100);
        // SLIDE - DRAW: ricordate Automobile e AutomobileElettrica,
        // MENTIMETER: posso metterle nel parcheggio?

        AutomobileElettrica b = new AutomobileElettrica();
        Automobile a = new Automobile();
        p.aggiungi(a);
        p.aggiungi(b);
        // SLIDE: a cosa serve?
        // back
    }


    private static void dynamic_binding() {
        int k;
        // leggiamo in input un intero in k
//        Scanner sc= new Scanner(System.in);
//        System.out.print("Enter number: ");
//        int k= sc.nextInt();
        k = 1;

        // dichiariamo un VettoreDati
        VettoreDati p;
        // quanto vale p ora?
        // inizializziamo diversamente in base a k
        if (k==1) {
            p = new Pila();
        }
        else {
            p = new Coda();
        }
        p.inserisci(1);
        p.inserisci(2);
        int j = p.estrai();
        System.out.println(j);
        // MENTIMETER: cosa succede qui?
        // SLIDE: decisioni al volo
        // back
    }

    private static void dynb_persona(){
        Persona per = new Studente("Giovanni");
        per.chiSei();
//        Studente ss = new Persona("sad");
        Persona p = new Persona("asd");
        p.chiSei();
        Studente s = new Studente("sss");
        s.chiSei();

        //SLIDE: tipo statico e tipo dinamico
        // MENTIMETER:
        //  e il tipo statico in dynamic_binding di p ?

        // tipo statico : vediamo anche con i suggerimenti di IntelliJ che tipo e`
        // per esempio, non ci suggerisce   p.matricola()
        // SLIDE: regole
        // back
    }

}
