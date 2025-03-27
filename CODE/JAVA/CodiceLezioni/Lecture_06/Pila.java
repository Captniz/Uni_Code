package Lecture_06;

public class Pila extends VettoreDati {

    public Pila(int size){
        super(size);
    }

    public Object estrai() {
        assert(marker>0):"Estrazione da Pila vuota";
        return contenuto[--marker];
    }
}
