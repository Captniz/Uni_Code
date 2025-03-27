package Lecture_16;

import java.io.*;
import java.util.EmptyStackException;
import java.util.Scanner;

public class Lecture_16 {
    public static void main(String[] args) {
        // SLIDE il problema
        // SLIDE gestione
        // SLIDE eccezione
//        leggiFile_noerrors();
//        leggiFile_traditionalerrors();
        // i metodi di sopra non li possiamo veramente scrivere in Java
        leggiFile_exceptions();
        // SLIDE propagare gli errori
        // SLIDE eccezioni in java
        Pila s = new Pila();
        try {
            Object o = s.estrai();
        } catch(EmptyStackException e) {
            System.out.println("Stack vuoto!");
            System.exit(1);
        }
        // SLIDE delimitare
        // SLIDE propagazione
        // SLIDE un esempio
        try {
            Lecture_16 l = new Lecture_16();
            l.m1();
        } catch (TestException e) {
            // ...
        }
        // SLIDE gestire o propagare
        FileInputStream f = null;
        String filename = "";
        try {
            f = new FileInputStream(filename);
            //
        } catch(IOException ioe) {
            //
        } finally {
        //            f.close();
        }
        // SLIDE finally
        // SLIDE eccezioni ereditarieta`
        // SLIDE gestori
        // MENTIMETER: dove viene catchata?
        FileOutputStream ff = null;
        try {
            ff = new FileOutputStream("f.dat");
        } catch (FileNotFoundException fnfe){
            System.out.println("FNF");
        }
        catch (IOException ioe){
            System.out.println("IOE");
        }
        catch (SecurityException se){
            System.out.println("SE");
        } catch (Exception e){
            System.out.println("E");
        }
        // SLIDE eccezioni, poly`
        // vediamo le classi A e B
        // MENTIMETER: quali definizioni sono corrette in B?

        // SLIDE throwable sottoclassi
        // SLIDE runtime
        // SLIDE info
        try {
            Data d = new Data(10, 12, 14);
        } catch (DataIllegale d){
            // ...
        }
        // SLIDE eccezioni e debugging
        // SLIDE suggerimenti

        // SLIDE input console
        read_from_console();
        // SLIDE input fx
        // vediamo UserInput
        // SLIDE stringa o intero
    }


    private static void leggiFile_exceptions() {
        File file = null;   // a path in the filesystem
        file = new File("filename.txt");
        try {
            file.createNewFile();       // needs exc
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            FileInputStream fis=new FileInputStream(file); // needs exc
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    // la firma di questi metodi e` cambiata, abbiamo una nuova keyword:  throws
    void m1() throws TestException {
        m2();
    }
    void m2() throws TestException {
        m3();
    }
    void m3() throws TestException {
        throw new TestException();
    }

    // possiamo definire le nostre eccezioni!
    class TestException extends Exception{}

    private static void read_from_console(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Nome: ");
        String nome = scanner.next();
        int eta = 0;
        boolean ok = false;
        System.out.println("Eta': ");
        while (!ok) {
            if (scanner.hasNextInt()) {
                eta = scanner.nextInt();
                ok = true;
            } else {
                scanner.next();
                System.out.println("L'età deve essere un valore intero!");
            } }
        scanner.close();
        System.out.println("Mi chiamo " + nome + " e ho " + eta + " anni.");
    }
    // back
}

class A{
    void f(){}
    void g() throws Exception{}
    void h() throws Exception{}
}
class B extends A{
    /*
    void f() throws Exception{}
    void g() throws Exception{}
    void h() throws DataIllegale{}
     */
}

class DataIllegale extends Exception { int giorno, mese, anno;
    DataIllegale(int g, int m, int a) {
        giorno = g; mese = m; anno = a;
    }
}
class Data {
    private int giorno, mese, anno;
    private boolean corretta(int g,int m,int a) {
        return false;
    }
    public Data(int g, int m, int a) throws DataIllegale {
        if(!corretta(g,m,a)) {
            throw new DataIllegale(g,m,a);
        }
        giorno = g; mese = m; anno = a;
    }
}
