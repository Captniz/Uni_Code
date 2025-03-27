package Lecture_05;

import Lecture_04.Automobile;

class Parcheggio {
    private Automobile buf[];
    private int nAuto;

    public Parcheggio(int dim) {
        buf=new Automobile[dim];
    }
    public void aggiungi(Automobile a) {
        buf[nAuto++]=a;
    }
}