package Lecture_05;

public class Coda extends VettoreDati{

    public Coda(){
        // final si usa per le costanti, tutte maiuscole, e per altro che vedremo
        final int DEFAULT_SIZE = 10;
        size = DEFAULT_SIZE;
        marker = 0;
        contenuto = new int[DEFAULT_SIZE];
    }

    public boolean iscoda(){
        return true;
    }

    public int estrai() {
        assert(marker>0);
        int retval = contenuto[0];
        for(int k=1; k<marker; k++){
            contenuto[k-1] = contenuto[k];
        }
        marker--;
        return retval;
    }
}
