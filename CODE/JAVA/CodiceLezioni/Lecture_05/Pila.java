package Lecture_05;

public class Pila extends VettoreDati{

    public Pila(){
        // final si usa per le costanti, tutte maiuscole, e per altro che vedremo
        final int DEFAULT_SIZE = 10;
        size = DEFAULT_SIZE;
        marker = 0;
        contenuto = new int[DEFAULT_SIZE];
    }


    public int estrai(){
        assert(marker>0);
        System.out.println("estraggo");
        marker --;
        int indx = marker;
        return contenuto[indx];
    }
}
