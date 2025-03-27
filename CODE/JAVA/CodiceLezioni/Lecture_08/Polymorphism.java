package Lecture_08;

import java.util.LinkedList;
import java.util.List;

public class Polymorphism {

    public static void test_nopoly(){
        List listaDiNumeri=new LinkedList();
        listaDiNumeri.add(new Number(1));
        listaDiNumeri.add(new Number(2));
        Number n1 = (Number) listaDiNumeri.get(0);
        Number n2 = (Number) listaDiNumeri.get(1);
        listaDiNumeri.add(new Papera());
        // Q: what will happen when we run this?
//        Number n3 = (Number) listaDiNumeri.get(2);
//        Lecture_08.println("N1: "+n1+" N2: "+n2+" N3: "+n3);
    }

    public static void test_poly(){
        List<Number> listaDiNumeri=new LinkedList();
        listaDiNumeri.add(new Number(8));
        listaDiNumeri.add(new Number(7));
        //Q: will this line compile? Are the types ok?
//        listaDiNumeri.add((Number)(new Papera()));
        Number n1 = listaDiNumeri.get(0);
        Number n2 = listaDiNumeri.get(1);
        Lecture_08.println("N1: "+n1+" N2: "+n2);
    }
}
//back

class Papera{
    Papera(){}
}
