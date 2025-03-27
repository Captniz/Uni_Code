package Lecture_05;

public class Esercizio1ABC {
    public static void esercizio(){
        A a1, a2;
        B b1;
        C c1;
        a1 = new B();
        b1 = new B();
        c1 = new C();
        a2 = new C();
        b1.stampa(b1);
        /// START
        // why A ora?
        a1.stampa(b1);
//        ((B)a1).stampa(b1);
        b1.stampa(c1);
        c1.stampa(c1);
        c1.stampa(a1);
        a2.stampa(c1);
    }
}


class A {
    public void stampa(A p) {
        System.out.println("A"); }
}
class B extends A {
    public void stampa(B p) {
        System.out.println("B");
    }

//    public void stampa(A p) {
//        System.out.println("A-B");
//    }
}
class C extends A {
    // e se cambiamo cosi`?
//    class C extends B {
    public void stampa(C p) {
        System.out.println("C");
    }
    public void stampa(A p) {
        System.out.println("A-C");
    }
}