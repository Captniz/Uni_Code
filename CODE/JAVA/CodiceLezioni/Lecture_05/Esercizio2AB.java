package Lecture_05;

public class Esercizio2AB {
    public static void esercizio(){
        AA a1, a2;
        BB b;
        a1 = new AA(4);
        a2 = new BB(5);
        b = new BB(6);
        System.out.println(a1.somma(a2));
        System.out.println(a2.somma(b));
        System.out.println(b.somma(a1));
        System.out.println(b.somma(b));
    }
}

class AA {
    private int val;
    public AA(int v) {
        val = v;
    }
    public int valore() {
        return val;
    }
    public int somma(AA o) {
        return valore() + o.valore();
    }
}
class BB extends AA {
    BB(int v) {
        super(v);
    }
    public int somma(AA o) {
        return valore() + o.valore() + 2;
    }
    public int somma(BB o) {
        return valore() + o.valore() + 1;
    }
}