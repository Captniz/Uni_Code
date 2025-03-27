package Lecture_05;

import Lecture_03.Pila;

// abstract -> nuovo qualificatore per la classe
// necessario se c'e` almeno un metodo abstract
abstract public class VettoreDati {
    int size;
    int defaultGrowthSize;
    int marker;
    int contenuto[];

    // i metodi possono esssere abstract, le sottoclassi devono implementarlo
    // Coda e Pila (sottoclassi di VettoreDati) estraggono in modo diverso
    // TODO: quando usare abstract?
    abstract public int estrai();
    // vedere Coda e Pila, hanno il codice scritto in precedenza
    //  nota che si cambia la gerarchia!

    // i campi non possono essere abstract, logicamente
    // questo e` un errore
//    abstract int sizes;

    // posso creare costruttori, ma non hanno molto senso,
    // se creo un oggetto di tipo VettoreDati devo anche specificare estrai
    // cioe` tutti i metodi abstract
    public VettoreDati(){
        size = 10;
        defaultGrowthSize = 5;
    }

    // questi metodi sono sempre gli stessi
    // ma ora sono qui, invece che duplicati in Pila e Coda
    public boolean piena() {
        return this.size == this.marker;
    }
    private void cresci(int delta){
        System.out.println("entro in cresci");
        size+=delta;
        int[] temp = new int[size];
        for (int k=0; k<marker ; k++){
            temp[k] = contenuto[k];
        }
        contenuto = temp;
    }
    public void stampastato(){
        System.out.println("==================");
        System.out.println("size ="+size);
        System.out.println("marker ="+marker);
        for (int k=0; k<marker; k++){
            System.out.println("[" + contenuto[k] + "]");
        }
        System.out.println("==================");
    }
    public void inserisci(int k){
        if (this.piena()){
            this.cresci(defaultGrowthSize);
        }
        contenuto[marker] = k;
        marker++;
    }

    // e la copia?
    // serve una cosa che vedremo piu` avanti: instanceof

//    public VettoreDati copia(){
//        Lecture_03.Pila to = new Pila(this.size);
//        for (int k=0; k<marker; k++){
//            to.contenuto[k] = contenuto[k];
//        }
//        to.marker = marker;
//        return to;
//    }

}
