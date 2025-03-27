package Lecture_08;

import java.util.*;

public class Lecture_08 {
    // SLIDEs (7): collections
    public static void main(String[] args){
        // SLIDE : operazioni di base, le testiamo in diverse funzioni
        // SLIDE : operazioni di base: generiche
        Collection<Number> c_list = new ArrayList<>();
        testempty(c_list);
        testsize(c_list);
        //MENTIMETER: what does c_list contain now?
        testempty(c_list);
        testcontain(c_list);
        Collection<Number> c_set = new HashSet<Number>();
        testsize(c_set);
        //MENTIMETER: what will the difference between the next two calls to testadd(.) be?
        testadd(c_list);
        testadd(c_set);
        // SLIDE: bulk
        cleartest(c_list);
        // SLIDE: operazioni sulle Liste
        listtest((List<Number>) c_list);
        // SLIDE: ancora pile e code 2x
        Map<String,Number> c_map = new HashMap<>();
        // SLIDE: Map 2x
        // SLIDE Map generic
        // TODO add moto code
        maptest(c_map);
        // SLIDE: collection e array
        // SLIDE avvisi
        // SLIDE: arraylist o linkedlist?
        // SLIDE: hashset o Treeset?

        // SLIDE: number -> vediamolo
        // SLIDE arraydati -> vediamolo
        // SLIDE: coda
        ArrayDati c = new Coda();
        ArrayDati p = new Pila();
        System.out.println("Testing on Coda [FIFO], adding 1, 2, 3");
        testinsert(c);
        System.out.println("Testing on Pila [LIFO], adding 1, 2, 3");
        testinsert(p);

        // code examples
        Polymorphism.test_nopoly();
        Polymorphism.test_poly();

        //SLIDES: visita di una collection
        CollectionIterator.test_iterator();
        CollectionIterator.test_for();
        CollectionIterator.test_twodice();
        CollectionIterator.test_remove();

        // SLIDES: esercitazione
    }
    /// the next 2 functions are just for personal taste and usage
    public static void println(String s){
        System.out.println(s);
    }
    public static void printoperating(Collection<Number> c){
        println("Operating on collection "+c.getClass().toString());
    }
    /// take a collection, print it, print whether it is empty
    public static void testempty(Collection<Number> c){
        printoperating(c);
        println("Collection is empty: "+c.isEmpty());
    }
    /// take a collection, print it, print its size, add a cat,
    // print its size, add a number, print the size
    public static void testsize(Collection c){
        printoperating(c);
        println("Size of collection is: "+ c.size());
        String cat = "cat";
        c.add(cat);
        println("Size of collection is: "+c.size());
        Number n = new Number(1);
        //TODO-Q: will the line below compile? Do the types make sense and why?
        c.add(n);
        println("Size of collection is: "+c.size());
    }
    /// take a collection, print it, print if it contains a Number, add that number, print if it contains that number
    public static void testcontain(Collection<Number> c){
        printoperating(c);
        Number n = new Number(9);
        println("Collection contains: "+n.prettyprint()+"? "+c.contains(n));
        c.add(n);
        println("Collection contains: "+n.prettyprint()+"? "+c.contains(n));
    }
    /// take a collection, print it, for two times, do: add a number and print if it succeeded
    public static void testadd(Collection<Number> c){
        printoperating(c);
        Number n = new Number(7);
        println("Element "+n.prettyprint()+" added to collection: "+c.add(n));
        println("Element "+n.prettyprint()+" added to collection: "+c.add(n));
    }
    // take a collection, print it, clear it, test if it is empty
    public static void cleartest(Collection c){
        printoperating(c);
        c.clear();
//        c.toArray();
        testempty(c);
    }
    // take a list, add two numbers multiple times, add a third number, print the index of a repeated object
    public static void listtest(List<Number> l){
        Number n1 = new Number(1);
        Number n2 = new Number(2);
        Number n3 = new Number(3);
        l.add(0,n1);
        l.add(0,n2);
        l.add(0,n1);
        l.add(1,n2);
        // Q : what does the list look like in memory?
        println("N1:"+n1+" N2: "+n2);
        println(l.toString());
        //
        // [] -> [n1-1] -> [n2-1::n1-1] -> [n1-2::n2-1::n1-1] -> [n1-2::n2-2::n2-1::n1-1]
        l.set(1, n3);
        //Q: and now?
        println(l.toString());
        println("Element 1 :"+l.get(1));
        //
        // [n1-2:::n3::n2-1::n1-1]
        println("Index of "+n1.prettyprint()+" is: "+l.indexOf(n1));
        println("Last Index of "+n1.prettyprint()+" is: "+l.lastIndexOf(n1));
        l.remove(1);
        println("Removing: "+l.toString());
        Collection<Number> cn1 = new ArrayList<Number>();
        cn1.add(n1);
        l.removeAll(cn1);
        println(l.toString());
    }
    public static void maptest(Map<String,Number> m){
        Number n1 = new Number(1);
        Number n2 = new Number(2);
        Number n3 = new Number(3);
        String k1 = "N1";
        String k2 = "N2";
        String k3 = "N3";
        String k4 = "N4";

        Object r1 = m.put(k1, n1);
        Object r2 = m.put(k1, n2);
        //MENTIMETER: what are r1 and r2?
        System.out.println("r1: "+r1+" and r2:"+r2);
        m.put(k1, n1);
        m.put(k2, n2);
        m.put(k3, n3);
        println("Getting "+k3+" : "+m.get(k3));
        println("sz: "+m.size());
        println("Removing "+k3+" : "+m.remove(k3));
        println("sz: "+m.size());
        println("Getting "+k3+" : "+m.get(k3));
        // MENTIMETER: predict the output of the prints below
        println("Map contains Key "+k1+" : "+m.containsKey(k1));
        println("Map contains Key "+k4+" : "+m.containsKey(k4));
        println("Map contains value "+n1.prettyprint()+" :"+m.containsValue(n1));
        println("Size of map: "+m.size());
    }

    //FIXME: introduce generics
    // Collection -> Collection<Object>
    // Map -> Map<String, Object>

    public static void testinsert(ArrayDati a){
        a.inserisci(1);
        a.inserisci(2);
        a.inserisci(3);
        for(int k=0;k<=4;k++){
            int v = a.estrai();
            if (v == -1) {
                break;
            }
            System.out.println("Estraggo: "+v);
        }
    }
}
