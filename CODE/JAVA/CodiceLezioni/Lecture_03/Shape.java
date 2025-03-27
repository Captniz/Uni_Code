package Lecture_03;

public class Shape {
    private int f;
    private static int ff;
    static Screen screen = new Screen();
    static void setScreen(Screen s) { screen=s; ff++; System.out.println(ff); }
    void show() { f++; }
}
class Screen{}

class Main{
    public static void main(String[] args){
        // MENTIMETER: per ogni linea: compila/non compila
        Shape.setScreen(new Screen());
//        Shape.show();
        Shape s1 = new Shape();
        Shape s2 = new Shape();
        Screen s = new Screen();
        s1.setScreen(s);
        s2.setScreen(s);
        s1.show();
        // back to main
    }
}