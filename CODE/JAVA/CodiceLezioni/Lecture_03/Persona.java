package Lecture_03;

public class Persona {
    private String nome;
    public int eta;
    public static int z = 10;

    public Persona(String nome) {
        this.nome = nome;
        eta = 0;
    }
//    public Persona(String nome, int eta) {
//        this(nome);
//        this.eta = eta;
//    }
    public void chiSei() {
        System.out.print("Ciao, io sono " + nome);
    }

    public void pp(){}
}