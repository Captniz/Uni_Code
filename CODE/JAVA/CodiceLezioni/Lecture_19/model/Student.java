package Lecture_19.model;

public class Student {
    private int age;
    private String name;

    public Student(int a, String n){
        this.age = a;
        this.name = n;
    }

    public int getAge() { return age; }
    public String getName() { return name; }
    // perche` ha piu` senso usare getter e setter
    // invece che fare un attributo pubblico in questo caso?
    //  per esempio, il client (UI) potrebbe mandare info non giuste
    //  e noi vogliamo per. es. metter tutti i nomi capitalised
    public void setName(String n) { this.name = n; }

    public void ringiovanisci() { this.age--; }
}
