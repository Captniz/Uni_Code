package Lecture_06;

import jdk.jfr.Experimental;

public class EsercizioAnimali {
    public static void esercizio(){
        // MENTIMETER: quali linee non funzionano?
        /*
        Animale g = new Gatto();
        Acquatico t = new Trota();
        Anatra a = new Anatra();
        Acquatico c = new Acquatico();
        Volatile l = g;
        Volatile v = a;
        Acquatico q = a;
        g.vola();
        v.vola();
        t.nuota();
        a.nuota();
        */
    }
}

abstract class Animale{}
interface Volatile{
    public void vola();
}
interface Acquatico{
    public void nuota();
}
class Gatto extends Animale{}
class Cavallo extends Animale{}
class Rondine extends Animale implements Volatile{
    public void vola(){}
}
class Trota extends Animale implements Acquatico{
    public void nuota(){}
}
class Anatra extends Animale implements Volatile, Acquatico{
    public void vola(){}
    public void nuota(){}
}


