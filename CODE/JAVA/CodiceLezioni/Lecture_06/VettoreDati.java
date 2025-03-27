package Lecture_06;

// cos'e` questo implements? lo vedremo dopo
public abstract class VettoreDati implements AccessoDati{
    int size;
    final int defaultGrowthSize = 5;
    int marker;
    // non sono piu` int, sono Object
    Object contenuto[];

    public VettoreDati(int dim) {
        size = dim;
        marker = 0;
        contenuto = new Object[size];
    }
    final public void inserisci(Object k) { if(marker == size)
        cresci(defaultGrowthSize); contenuto[marker] = k; marker++;
    }
    private void cresci(int delta){
        System.out.println("entro in cresci");
        size+=delta;
        Object[] temp = new Object[size];
        for (int k=0; k<marker ; k++){
            temp[k] = contenuto[k];
        }
        contenuto = temp;
    }
    abstract public Object estrai();
}