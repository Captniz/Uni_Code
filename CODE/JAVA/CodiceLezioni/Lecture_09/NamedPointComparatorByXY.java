package Lecture_09;

import java.util.Comparator;

class NamedPointComparatorByXY implements Comparator<NamedPoint> {
    public int compare(NamedPoint p1, NamedPoint p2) {
        // equivalente al confronto naturale in Point
        int retval = p1.y - p2.y;
        if (retval == 0) {
            retval = p1.x - p2.x;
        }
        return retval;
    }
}