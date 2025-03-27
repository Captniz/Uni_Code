package Lecture_09;

class NamedPoint extends Point {
    String name;

    NamedPoint(String s , int x, int y) {
        super(x, y);
    }
    public String getName() {
        return name;
    }
}