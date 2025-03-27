package Lecture_07;

// 2 parametri di tipo
public class PairO {
    private Object first;
    private Object second;

    public PairO(Object a1, Object a2) {
        first = a1;
        second = a2;
    }
    // la visibilita` dei parametri definiti in cima e` per tutta la classe
    // qui usiamo X e Y come tipo di ritorno, come tipo dei parametri dei metodi
    public Object getFirst() { return first; }
    public Object getSecond() { return second; }
    public void setFirst(Object arg) {first = arg;}
    public void setSecond(Object arg) {second = arg;}
}