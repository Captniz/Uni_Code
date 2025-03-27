package Lecture_17.clone;

public class Test {
    // SLIDE
    // SLIDE Metodo clone di object
    //     protected!
    //     some properties

    public static void main(String []a){
        new Test();
    }

    Test(){
        // SLIDE
        P p1=new P();
        p1.x=1;
        p1.y=2;
        P p2=p1;
        // MENTIMETER: posso chiamarlo?
//        P p3=(P)(p1.clone());
        // System.out.println(p3);

        // SLIDE
        Q q1 = new Q();
        q1.x=5;
        Q q2 = q1;
        Q q3 = (Q) q1.clone();
        System.out.println(q1);
        System.out.println(q2);
        System.out.println(q3);
        q1.x=7;
        // MENTIMETER:
        System.out.println(q1);
        System.out.println(q2);
        System.out.println(q3);

        // SLIDE
        V v1 = new V(5);
        V v2 = (V) v1.clone();
        System.out.println(v1);
        System.out.println(v2);
        v1.x[0] = 9;
        System.out.println(v1);
        System.out.println(v2);

        // SLIDE
        W w1 = new W(5);
        W w2 = (W) w1.clone();
        System.out.println(w1);
        System.out.println(w2);
        w1.x[0] = 9;
        System.out.println(w1);
        System.out.println(w2);

        // SLIDE 3x
    }
}

class P {
    int x;
    int y;

    public String toString() {
        return ("x=" + x + " ; y=" + y);
    }
}

class Q implements Cloneable{
    int x;

    public String toString() {
        return (""+x);
    }
    public Object clone(){
        try{
            return super.clone();
        } catch (CloneNotSupportedException e){
            System.exit(1);
        }
        return null;
    }
}

class V implements Cloneable{
    int[] x;

    V(int s){
        x = new int[s];
        for (int k=0;k<x.length;k++) {
            x[k]=k;
        }
    }
    public String toString() {
        String s="";
        for (int k:x) {
            s=s+x[k]+ "";
        }
        return s;
    }

    public Object clone(){
        try{
            return super.clone();
        } catch (CloneNotSupportedException e){
            System.exit(1);
        }
        return null;
    }
}

class W implements Cloneable{
    int[] x;

    W(int s){
        x = new int[s];
        for (int k=0;k<x.length;k++) {
            x[k]=k;
        }
    }
    public String toString() {
        String s="";
        for (int k:x) {
            s=s+x[k]+ "";
        }
        return s;
    }

    public Object clone(){
        Object tmp = null;
        try{
            tmp = super.clone();
        } catch (CloneNotSupportedException e){
            e.printStackTrace();
            return null;
        }
        // clone the array!
        ((W) tmp).x = new int[x.length];
        for (int k:x){
            ((V)tmp).x[k]=x[k];
        }
        return tmp;
    }
}

// back