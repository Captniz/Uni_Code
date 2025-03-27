package Lecture_06;

public class Esercizio2AB {
    public static void esercizio(){
        A a;
        B b = new B(); // B b = new C();
        // upcast implicito dovuto al polimorfismo
        a = b;
        a.f1();
        // a.f2();'
        // downcast esplicito
        ((B) a).f2();
        // MENTIMETER: cosa succede qui?
//        ((CC) a).f3();
        // MENTIMETER: e se avessimo definito b diversamente? B b = new C();
    }
}

class A {
    void f1() {
        System.out.println("F1");
    }
}
class B extends A {
    void f2() {
        System.out.println("F2");
    }
}
class CC extends B {
    void f3() {
        System.out.println("F3");
    }
}
