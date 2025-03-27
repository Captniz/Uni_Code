package Lecture_07;

// 2 parametri di tipo
public class Pair<X,Y> {
    private X first;
    private Y second;

    public Pair(X a1, Y a2) {
        first = a1;
        second = a2;
    }
    // la visibilita` dei parametri definiti in cima e` per tutta la classe
    // qui usiamo X e Y come tipo di ritorno, come tipo dei parametri dei metodi
    public X getFirst() { return first; }
    public Y getSecond() { return second; }
    public void setFirst(X arg) {first = arg;}
    public void setSecond(Y arg) {second = arg;}
}