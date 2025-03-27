package Lecture_16;

import java.util.EmptyStackException;

public class Pila {

    private int size;
    protected int marker;
    protected int[] contenuto;

    public boolean piena() {
        return this.size == this.marker;
    }

    public Pila(int initialSize) {
        size = initialSize;
        marker = 0;
        contenuto = new int[initialSize];
    }
    public Pila(){
        final int DEFAULT_SIZE = 10;
        size = DEFAULT_SIZE;
        marker = 0;
        contenuto = new int[DEFAULT_SIZE];
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

    public Pila copia(){
        Pila to = new Pila(this.size);
        for (int k=0; k<marker; k++){
            to.contenuto[k] = contenuto[k];
        }
        to.marker = marker;
        return to;
    }

    public int estrai() throws EmptyStackException {
        if (this.marker == 0 ) {
            return contenuto[--marker];
        }
        else {
            throw new EmptyStackException();
        }
    }

    // finiamo di analizzare la Pila in Java
    public void stampastato(){
        System.out.println("==================");
        System.out.println("size ="+size);
        System.out.println("marker ="+marker);
        for (int k=0; k<marker; k++){
            System.out.println("[" + contenuto[k] + "]");
        }
        System.out.println("==================");
    }

    // SLIDE: costanti
    public void inserisci(int k){
        final int GROWTH_SIZE = 5;
        if (this.piena()){
            this.cresci(GROWTH_SIZE);
        }
        contenuto[marker] = k;
        marker++;
    }
    // SLIDE: paragone: i globali in Java VS i globali in C

    // torniamo in cima, e parliamo dell'ultima cosa: package
    // cos'e` un package
    // cosa e` la visibilita` package
    // SLIDE: package
    // SLIDE java.lang
}