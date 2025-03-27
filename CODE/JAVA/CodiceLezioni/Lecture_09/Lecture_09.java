package Lecture_09;

import Lecture_04.Automobile;

import java.util.*;

public class Lecture_09 {
    public static void main(String[] args){
        // intro
       test_eq();

       test_hash();

       test_comp();
    }

    private static void test_eq(){
        // SLIDE: uguaglianza
        int k1 = 1;
        int k2 = 1;
        System.out.println(k1==k2);

        // creiamo una classe P (di sotto)
        // SLIDE uguaglianza
        P p1=new P();
        p1.x=1;
        p1.y=2;
        P p2=new P();
        p2.x=1;
        p2.y=2;
        // MENTIMETER: p1 e o2 sono uguali?
        // System.out.println(p1==p2);
        // SLIDE 3x
        System.out.println(p1);
        System.out.println(p2);
        p1.x=3;
        System.out.println(p1);
        System.out.println(p2);
        //SLIDE oggetti diversi
        System.out.println(p1);
        P ppp2=p1;
        ppp2.x=3;
        System.out.println(p1);
        // SLIDE
        // SLIDE ==
        // SLIDE
        // SLIDE equals
        P ep1=new P();
        ep1.x=1; ep1.y=2;
        P ep2=new P();
        ep2.x=1; ep2.y=2;
        System.out.println(ep1.equals(ep2));
        // SLIDE metodo equals
        // SLIDE equals errato
        // SLIDE funziona?
        // SLIDE equals overloading o overriding
        // SLIDE equals ridefinito
        // andiamo a vedere il ridefinito

        // SLIDE altro problema
        Integer ip2=new Integer(3);
        System.out.println(ep1.equals(ip2));
        // SLIDE: soluzione (non vediamo il codice ancora)
        // SLIDE
        // SLIDE altro problema
        P np2=null;
        System.out.println(ep1.equals(np2));
        System.out.println(ep1==np2);
        // SLIDE:  soluzione (non vediamo il codice ancora)
        // SLIDE e le sottoclassi
        Q q2 = new Q();
        q2.x=1; q2.y=2;
        // problema, dice true (se non abbiamo la soluzione giusta e abbiamo solo la instanceof),
        // ma sono oggetti di classi diverse! vogliamo veramente che siano equals
        // decommentiamo la .getClass
        System.out.println(ep1.equals(q2));
        System.out.println(ep1==q2);
        // SLIDE: e le sottoclassi 2x
        // SLIDE proprieta` di equals
        // back
    }

    private static void test_hash(){
        // SLIDE ridefinire la equals
        // SLIDE hashcode
        // SLIDE proprieta` di hashcode
        // SLIDE in sostanza 2x
        // SLIDE hash example
        // SLIDE un buon hash :: do not roll your own crypto!!
        // SLIDE nel dubbio
        // MENTIMETEr:
        // SLIDE esempio
        Set<Element> s = new HashSet<>();
        Random r = new Random();
        for (int i = 0; i < 10; i++) {
            s.add(new Element(r.nextInt(10)));
        }
        System.out.println("Set elements: " + s);
        // SLIDE: esempio 2x
        System.out.print("Hashcodes: ");
        for (Element t : s) {
            System.out.print(t.hashCode() + " ");
        }
        System.out.println("");
        Element toSearch = new Element(5);
        System.out.print("toSearch in set? ");
        if (s.contains(toSearch)) {
            System.out.println("yes");
        }
        else {
            System.out.println("no");
        }
        System.out.println("Hashcode of toSearch: " + toSearch.hashCode());
        // decommentiamo la hashcode
        // SLIDE
        //back
    }

    private static void test_comp(){
        // SLIDE insiemi ordinati
        SortedSet<Element> s = new TreeSet<>();
        Random r = new Random();
        for (int i = 0; i < 10; i++){
            s.add(new Element(r.nextInt(10)));
            // runtime exception!
        }
        System.out.println("Set elements: " + s);
        // SLIDE ordinamento
        // SLIDE comparable

        s = new TreeSet<>();
        for (int i = 0; i < 10; i++){
            s.add(new CElement(r.nextInt(10)));
        }
        System.out.println("Set elements: " + s);
        // SLIDE a cosa serve comparable
        // SLIDE esempio
        List<Car> macchine;
        macchine = new LinkedList<Car>();
        Car a = new Car(100, "Fiat Cinquecento");
        macchine.add(a);
        Car b = new Car(250, "Porsche Carrera");
        macchine.add(b);
        Car c = new Car(180, "Renault Megane");
        macchine.add(c);
        System.out.println(macchine);
        Collections.sort(macchine);
        System.out.println(macchine);
        // SLIDE esempio 2x, con e senza generics

        // SLIDE 50
        // definiamo Point e NamedPoint che estendono Comparable
        List<Point> l = new LinkedList<>(); l.add(new Point(40,20));
        l.add(new Point(10,20));
        l.add(new Point(20,10));
        l.add(new Point(20,20));
        System.out.println(l);
        Collections.sort(l);
        System.out.println(l); l.clear();
        l.add(new NamedPoint("B",40,20));
        l.add(new NamedPoint("D",10,20));
        l.add(new NamedPoint("C",20,10));
        l.add(new NamedPoint("A",20,20));
        System.out.println(l);
        Collections.sort(l);
        System.out.println(l);
        // esercizio: e per ordinare per nome

        // SLIDE comparator + slides 3x
        List<NamedPoint> ll = new LinkedList<>();
        ll.clear();
        ll.add(new NamedPoint("B",40,20));
        ll.add(new NamedPoint("D",10,20));
        ll.add(new NamedPoint("C",20,10));
        ll.add(new NamedPoint("A",20,20));
        System.out.println(ll);
        Collections.sort(ll, new NamedPointComparatorByXY());
        System.out.println(ll);
        ll.clear();
        ll.add(new NamedPoint("B",40,20));
        ll.add(new NamedPoint("D",10,20));
        ll.add(new NamedPoint("C",20,10));
        ll.add(new NamedPoint("A",20,20));
        System.out.println(ll);
        Collections.sort(ll, new NamedPointComparatorByName());
        System.out.println(ll);

    }
}

class P {
    int x; int y;
    public String toString() {
        return ("x="+x+" ; y="+y);
    }
    // overloading -> cambio della firma
    public boolean equals(P var){
        return (x==var.x && y==var.y);
    }
    // overriding: equals su oggetti di tipo P, con parametro di tipo Object viene dynamically dispatched qui
    // e non alla equals di Object (ereditata di base da tutti)
    public boolean equals(Object var){
        // return (x==var.x && y==var.y);
        // MENTIMETER: posso far andare questo codice?
        // SLIDE funziona ?
        // back

        if (var == null) {
            return false;
        }
        if (!(var instanceof P)) {
            return false;
        }
        // decommentiamo
//        if (var.getClass() != this.getClass()) {
//            return false;
//        }
        return (x==((P)var).x && y==((P)var).y);
        // back
    }
}

class Q extends P {
    int z;
}

class Element {
    int x;
    public Element(int x) {
        this.x = x;
    }
    public String toString(){
        return x + "" ;
    }
    public boolean equals(Object obj) {
        if (this == obj) { return true; }
        if (obj == null) { return false; }
        if (getClass() != obj.getClass()) { return false; }
        if (this.x != ((Element) obj).x) { return false; }
        return true;
    }

//    public int hashCode() { return Objects.hash(x); }

}

class CElement extends Element implements Comparable<Element> {
    public CElement(int x) {
        super(x);
    }

    public int compareTo(Element o) {
        if(this.equals(o)) return 0;
        if(this.x < o.x) return -1;
        return 1;
    } }

class Car implements Comparable<Car>{
    public int maxSpeed;
    public String name;
    Car(int v, String name) {
        maxSpeed = v;
        this.name = name;
    }
    public String toString() {
        return "(" + maxSpeed + "," + name + ')';
    }
    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        if (!(o instanceof Car)) {
            return false;
        }
        return (this.maxSpeed ==((Car)o).maxSpeed && this.name == ((Car)o).name);
    }
    public int compareTo(Car o){
        if (this.equals(o)) return 0;
        if (maxSpeed < o.maxSpeed) return -1;
        return 1;
    }
}