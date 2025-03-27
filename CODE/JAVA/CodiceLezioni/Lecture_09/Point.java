package Lecture_09;

class Point implements Comparable<Point> {
    int x, y;

    Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int compareTo(Point p) {
        // ordino sulle y
        int retval = y - p.y;
        // a parità di y ordino sulle x
        if (retval == 0) {
            retval = x - p.x;
        }
        return retval;
    }
}