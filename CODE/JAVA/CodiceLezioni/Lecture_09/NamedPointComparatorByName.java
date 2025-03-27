package Lecture_09;

import java.util.Comparator;

class NamedPointComparatorByName implements Comparator<NamedPoint> {
    public int compare(NamedPoint p1, NamedPoint p2) {
        return p1.getName().compareTo(p2.getName());
    }
}
