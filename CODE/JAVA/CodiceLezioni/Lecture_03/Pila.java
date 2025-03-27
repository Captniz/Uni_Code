// cos'e` questo 'package'? lo vediamo dopo
package Lecture_03;

//import Lecture_04.PrivateClass;

// definiamo una classe con un modificatore di visibilta`: public
// si deve chiamare come il file
// vedremo che ci sono anche classi private
@SuppressWarnings("ALL")
public class Pila {

    private int size;
    protected int marker;
    // non c'e` *
    protected int[] contenuto;

    int contapile(){return 0;}

    public boolean piena() {
        int s ;
        Pila pp;
        // usiamo "." e non "->" per accedere alle variabili di istanza
        return this.size == this.marker;

        // ===== START
        // recap: class vs object + analogia biscotti
        // recap: sintassi di classe pila + campi + metodi
        // SLIDE: classi
        // (attributi / metodi) e oggetti
            // una classe contiene campi (variabili di istanza o attributi),
            //  e metodi
            // OGNI campo e metodo ha un modificatore di visibilta`:
            //  public / private / package / protected
            //  package e protected -> li vediamo tra un po'
            // i campi definiscono i loro tipi
            //  ogni tipo ha un valore base di inizializzazione!
            // i metodi hanno una firma, come le funzioni
        //
        // GOTO main, draw layout for s, w
        //

        // SLIDE classi e oggetti: riferimenti
            // null
            // puntatori
            // e` un paradigma nuovo, una idea che non avete
            // ancora visto ma che avete gia` usato

        // SLIDE: passaggio dei parametri
            // quali tipi abbiamo?
    }

    // SLIDE creazione e distruzione
    // anche i metodi e i costruttori hanno modificatori
    // il costruttore si chiama come la classe
    public Pila(int initialSize) {
        // andiamo a vedere nel main come viene usato
        size = initialSize;
        this.marker = 0;
        this.contenuto = new int[initialSize];
    }
    // SLIDE garbage collection
    // invocazione diretta: System.gc()
    protected void finalize(){
        // cose da fare quando viene distrutto un oggetto
    }

    // SLIDE classi e costruttori
    // possiamo avere piu costruttor, solo se hanno firma diversa
    // se mancano, viene inserito un costruttore di default
    //     senza parametri
    //     che inizializza tutto al valore di base
    public Pila(){ // stesso nome
        // final si usa per le costanti, tutte maiuscole,
        //  e per altro che vedremo
        this(10);
        final int DEFAULT_SIZE = 10;
//        size = DEFAULT_SIZE;
//        marker = 0;
//        contenuto = new int[DEFAULT_SIZE];
    }

    // SLIDE ancora sui costruttori
    // stiamo facendo OVERLOADING: metodi con lo stesso nome ma con firma diversa
    public Pila(char c){
        this(); //chiamiamo il costruttore di sopra
    }

    // SLIDE pila (cresci)
    //possiamo avere metodi privati
    //  andiamo in main e controlliamo che funzioni public/private
//    private void cresci(int delta, int c){}
    private void cresci(int delta){
        System.out.println("entro in cresci");
        this.size+=delta;
        // Array: questo e` un array di tipi base
        int[] temp = new int[this.size];
        // MENTIMETER: posso dichiarare un array di tipo int*?
        // int* temp2 = new int[size];
//        Pila p;

        for (int k=0; k<this.marker ; k++){
            temp[k] = this.contenuto[k];
        }
        // Una differenza colossale col C/C++, non dobbiamo
        //  fare memory management
        //  non dobbiamo fare delete contenuto
        this.contenuto = temp;
        // SLIDE cresci: implementazione alternativa
//         System.arraycopy(contenuto, 0, temp, 0, marker-1);
        // SLIDE arrayCopy
        // copia 'marker-1' elementi da contenuto a partire da 0 dentro temp a partire da 0
    }

    // copia: recap di notazione:
    //      parsing della firma: tipo di ritorno, tipo degli argomenti
    //  public, this, dot-notation
    public Pila copia(){
        Pila to = new Pila(this.size);
        for (int k=0; k<marker; k++){
            to.contenuto[k] = contenuto[k];
        }
        to.marker = marker;
        return to;
    }

    public int estrai(){
        // SLIDE: anche Java ha le asserzioni
        assert(this.marker>0) : "Estrazione errata";    // messaggio opzionale
        assert(this.marker>0);
        // SLIDE: equivalente a
//        if (! (marker > 0) ){
//            System.out.println("Estrazione errata");
//            System.exit(1);
//        }

        System.out.println("estraggo");
        int indx = this.marker;
        this.marker --;
        return this.contenuto[indx];
    }

    // SLIDE: pila in Java (main)

    public void stampastato(){
        System.out.println("==================");
        System.out.println("size ="+this.size);
        System.out.println("marker ="+this.marker);
        for (int k=0; k<this.marker; k++){
            System.out.println("[" + this.contenuto[k] + "]");
        }
        // Ok, cos'e` questo System?
        // SLIDE: system una libreria globale

        // Convenzioni di nomi:
        //  Maiuscola -> classe
        //  minuscola -> oggetto
        //  parentesi alla fine (), + argomenti -> metodo

        // MENTIMETER: cosa stiamo facendo qui?
        System.gc();
        // MENTIMETER: cosa stiamo facendo qui?
        System.out.println("==================");

        // GOTO back to main -> explain statics()
    }

    // SLIDE: costanti
    public void inserisci(int k){
        final int GROWTH_SIZE = 5; // come const in C
        if (this.piena()){
            this.cresci(GROWTH_SIZE);
        }
        this.contenuto[this.marker] = k;
        this.marker++;
    }
    // posso combinare i qualificatori
    final static public int WHAT= 6;
    static final private char WHO = 'c';

    // SLIDE: paragone: i globali in Java VS i globali in C
    //  differenza principale: fully global globals VS controlled-access globals

    // SLIDE: package
    // torniamo in cima, e parliamo dell'ultima cosa: package
    // cos'e` un package
    // cosa e` la visibilita` package
    //  -> visibilita`, vedere Lecture_04 -> Coda per imports cross-package
    // posso accedere a Persona
    Persona p = new Persona("spino");
    // vediamo PrivateClass dentro Lecture_04
//    PrivateClass pc = new PrivateClass(); // decommentare e controllare l'import
    // SLIDE java.lang

}