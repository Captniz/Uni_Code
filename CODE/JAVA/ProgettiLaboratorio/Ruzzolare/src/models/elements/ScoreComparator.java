package models.elements;

import java.util.Comparator;


public class ScoreComparator implements Comparator<Score> {
    @Override
    public int compare(Score s1, Score s2){
        if (s1.points==s2.points)
            return s1.name.compareTo(s2.name);

        if (s1.points> s2.points)
            return 1;

        return -1;
    }
}
