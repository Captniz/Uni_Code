public class Test {
    static final int MAX = 10;
    public static void main(String[] args) {
        A a = new A(10);
        A a1 = new C();
        A a2 = new B();
        C c1 = (C) a1;
        C c2 = (C) a2;
        a.m("dark");
        c1.m("light");
        c2.m("what");
    }
}

class A {
    A(int x) { }

    public int m(String s) {
        return s.length();
    }
}

class B extends A {
    B() { super(0); }
}

class C extends B {
    C() { super(); }
}
