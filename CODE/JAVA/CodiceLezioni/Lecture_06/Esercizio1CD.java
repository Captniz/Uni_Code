package Lecture_06;

public class Esercizio1CD {
    public static void esercizio(){
        C.m();
        D.m();
        C c = new C();
        C cd = new D();
        D d = new D();
        // IntelliJ si lamenta (ma lascia compilare), giustamente
        // MENTIMETER: posso avere C::m() statico e D::m() no?
        c.m();
        // MENTIMETER: se m() non fosse statico cosa verrebbe stampato?
        cd.m();
        d.m();
    }
}

class C {
    static void m() {
        System.out.println("1");
    }
}

class D extends C {
    static void m() {
        System.out.println("2");
    }
}
