package Lecture_04;

// SLIDEs
public class NamedPoint extends Point {
    String name;

    public NamedPoint(int x,int y,String name) {
        super(x,y); // prima istruzione! (costruttore)
        this.name = name;
    }
    public String toString(){ // overriding (da Point)
        return name + super.toString();
        // return name + " (" + x + "," + y + ")";
    }
}