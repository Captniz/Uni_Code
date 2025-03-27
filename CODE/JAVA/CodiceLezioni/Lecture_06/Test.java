package Lecture_06;

public class Test {
    public static void test_main(String a[]) {
        Test c = new Derived();
        c.f1();
    }
    // decommentare questo e la classe
    // final void f2() { System.out.println("f2 in superclass");}

    // SLIDE: private vs final methods
    private void f1() { System.out.println("f1 in superclass");}
}

//class Derived extends Test {
//    public void f2() { System.out.println("f2 in subclass");}
//}


class Derived extends Test {
    // questo non e` override di Test::f1
    public void f1() { System.out.println("f1 in subclass");}
}