package Lecture_08;

import java.util.*;

public class CollectionIterator {

    public static void test_iterator(){
        // SLIDE iteratori e filter
        ArrayDati s = new Coda();
        s.inserisci(1);
        s.inserisci(2);
        s.inserisci(3);
        System.out.println("Before filtering: "+s.toString());
        filter(s);
        System.out.println("After filtering: "+s.toString());

        /// ancora meglio: higher order!
        s.inserisci(4);
        s.inserisci(5);
        s.inserisci(6);
        Conditional modthree = (n) -> (n.getInt()%3==0);
        Conditional modtwo = (n) -> (n.getInt()%2==0);
        System.out.println("Before filtering (HO): "+s.toString());
        s.filter_higherorder(modthree);
        System.out.println("After filtering (HO): "+s.toString());
        s.filter_higherorder(modtwo);
        System.out.println("After filtering (HO): "+s.toString());
        // back
    }

    // needs to be static, or make as a method of Arraydati
    // codice polimorfico! funziona per Set, List, etc etc etc!
    private static void filter(Collection<Number> x) {
        Iterator<Number> i = x.iterator();
        while(i.hasNext()) {
            if(!cond(i.next()))
                i.remove();
        }
    }
    //
    private static boolean cond(Number n) {
        return n.getInt()>2;
    }

    public static void test_for(){
        List<Number> listaDiNumeri=new LinkedList();
        listaDiNumeri.add(new Number(1));
        listaDiNumeri.add(new Number(2));
        listaDiNumeri.add(new Number(5));
        listaDiNumeri.add(new Number(2));
        listaDiNumeri.add(new Number(7));
        // SLIDE: ciclo for generalizzato
        for (Number n : listaDiNumeri){
            System.out.println(n);
        }
        for(int i=0;i<listaDiNumeri.size(); i++){
            if(listaDiNumeri.get(i).getInt()==2){
                Number n = listaDiNumeri.remove(i);
                System.out.println("Rimosso"+listaDiNumeri.get(i));
            }
        }
    }

    public static void test_twodice(){
        List<String> faces = new ArrayList<>();
        faces.add("ONE"); faces.add("TWO");faces.add("THREE");faces.add("FOUR");faces.add("FIVE");faces.add("SIX");

        for(Iterator<String> i = faces.iterator(); i.hasNext();) {
            for (Iterator<String> j = faces.iterator(); j.hasNext(); ) {
                System.out.println(i.next() + " " + j.next());
            }
        }
        for(String i : faces) {
            for (String j : faces) {
                System.out.println(i + " " + j);
            }
        }
    }

    public static void test_remove(){
        Collection<Integer> c = new ArrayList<>();
        for(int i=0; i<10; i++) {
            c.add(i);
        }
        System.out.println(c);
        for(int i: c) {
            if(i%2 == 0) {
                c.remove(i);
            }
        }
        System.out.println(c);

        for(Iterator<Integer> i=c.iterator(); i.hasNext();){
            if(i.next() %2 ==0) {
                i.remove();
            }
        }
        System.out.println(c);
    }

}
