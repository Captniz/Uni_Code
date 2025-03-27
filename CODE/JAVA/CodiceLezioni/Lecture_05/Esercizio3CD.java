package Lecture_05;

public class Esercizio3CD {
    // SLIDE
    // MENTIMETER:
    public static void esercizio(){
        CC c = new CC();
        c.m();
        c.m(5);
//        c.m("hello");
        CC cd = new DD();
        cd.m(); cd.m(5);
//        cd.m("hello");
        DD d = new DD();
        d.m();
        d.m(5);
//        d.m("hello");
    }
    // back
}
class CC {
    public void m(){}
    public void m(int x){
        // overloads CC::m()
    }
}
class DD extends CC {
    public void m(){
        //overrides CC::m()
    }
    // DD eredita CC:m(int x)
    public void m(String x){
        // overloads DD::m(String)
    }
}
