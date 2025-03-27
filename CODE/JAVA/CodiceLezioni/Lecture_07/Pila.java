package Lecture_07;

import Lecture_03.Persona;
import Lecture_06.EsercizioAnimali;

import java.util.function.Function;

// coi generici abbiamo dei parametri di tipo, che vengono definiti nella classe
// i parametri di Tipo vanno tra parentesi angolari
// T e` il parametro di tipo
public class Pila<T>{
    int size;
    final int defaultGrowthSize = 5;
    int marker;
    // non sono piu`  Object, sono T
    T contenuto[];

    public Pila(int dim) {
        size = dim;
        marker = 0;
        // questa soluzione non e` propriamente soddisfacente
        // ma con le collections vedremo come evitarla
        contenuto = (T[]) new Object[size];
    }

    public T estrai() {
        assert(marker>0):"Estrazione da Pila vuota";
        return contenuto[--marker];
    }
    final public void inserisci(T k) {
        if(marker == size) {
            cresci(defaultGrowthSize);
        }
        contenuto[marker] = k;
        marker++;
    }
    private void cresci(int delta){
        System.out.println("entro in cresci");
        size+=delta;
        T[] temp = (T[]) new Object[size];
        for (int k=0; k<marker ; k++){
            temp[k] = contenuto[k];
        }
        contenuto = temp;
    }
    // back

    public static void stampaPila(Pila<Object> pila) {
        for (int k = 0 ; k < pila.marker; k++){
            System.out.println(pila.contenuto[k].toString() + " ");
        }
    }
    public void stampaPila2(Pila<?> pila) {
        for (int k = 0 ; k < pila.marker; k++){
            System.out.println(pila.contenuto[k].toString() + " ");
        }
    }


    public static double svuotaAggrega(Pila<? extends Number> p){
        double s = 0.0;
        for (int i=0; i<=p.marker; i++){
            s += p.estrai().doubleValue();
        }
        return s;
    }

    public <U> Pila<U> map(Function<T,U> f){
        // U u = new U();
        Pila<U> r = new Pila<U>(this.size);
        for (int k = 0 ; k < this.marker ; k ++){
            T elem = this.contenuto[k];
            r.inserisci(f.apply(elem));
        }
        return r;
    }
}



