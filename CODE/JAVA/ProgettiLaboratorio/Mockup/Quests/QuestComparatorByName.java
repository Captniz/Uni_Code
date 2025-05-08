package Quests;

import java.util.Comparator;

public class QuestComparatorByName implements Comparator<Quest> {
    @Override
    public int compare(Quest q1, Quest q2) {
        return q1.getName().compareTo(q2.getName());
    }
}
