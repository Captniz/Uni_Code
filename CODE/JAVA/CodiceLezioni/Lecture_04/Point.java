package Lecture_04;

public class Point {
    public int x = 0;
    public int y = 0;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public String toString() {
        // overriding (da Object)
        return "(" + x + "," + y + ")";
    }
    public void move(int x, int y){
        this.x = x;
        this.y = y;
    }
}