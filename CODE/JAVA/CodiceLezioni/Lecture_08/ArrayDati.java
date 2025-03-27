package Lecture_08;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

// possiamo estendere le classi di collection
//  per definire le nostre variazioni
public abstract class ArrayDati extends LinkedList<Number> {

    public void inserisci(int x) {
        Number n = new Number(x);
        this.add(n);
    }

    abstract public int estrai();
    // back
    ///NOTE: for later


    //A usage of iterators to overload the toString method
    public String toString(){
        String retstr = "ArrayList: [";
        Iterator<Number> i = this.iterator();
        while(i.hasNext()) {
            retstr+=i.next().prettyprint();
        }
        return retstr+"]";
    }

    //A usage of iterators to implement a higher-order function
    // lambdas in Java require an interface
    void filter_higherorder(Conditional cond) {
        Iterator<Number> i = this.iterator();
        while(i.hasNext()) {
            if(!cond.cond(i.next()))
                i.remove();
        }
    }
}

interface Conditional{
    boolean cond(Number n);
}

