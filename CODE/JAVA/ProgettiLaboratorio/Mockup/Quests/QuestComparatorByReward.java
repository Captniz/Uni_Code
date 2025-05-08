package Quests;

import java.util.Comparator;

public class QuestComparatorByReward implements Comparator<Quest> {
    @Override
    public int compare(Quest q1, Quest q2) {
        return q1.getReward() - q2.getReward();
    }
}
