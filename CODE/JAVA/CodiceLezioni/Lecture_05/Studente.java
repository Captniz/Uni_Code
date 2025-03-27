package Lecture_05;

import Lecture_03.Persona;

public class Studente extends Persona {
    public Studente(String nome) {
        super(nome);
    }

    public void chiSei() {
        super.chiSei();
        System.out.print("e sono uno studente");
        System.out.println();
    }

    public int matricola(){
        return 0;
    }
}