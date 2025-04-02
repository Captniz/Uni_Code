package mutations;

import data.Statistics;
import interfaces.*;
import data.Attributes;

public class Speed implements StatMut,StdMut {
    public Speed() {
    }

    @Override
    public void applyMutation(Attributes attr) {
        applyStat(attr.stats);
    }

    @Override
    public void removeMutation(Attributes attr) {
        removeStat(attr.stats);
    }

    @Override
    public void applyStat(Statistics stats) {
        stats.setDexterity(stats.getDexterity() + 2);
    }

    @Override
    public void removeStat(Statistics stats) {
        stats.setDexterity(stats.getDexterity() - 2);
    }

    @Override
    public String getName() {
        return "Speed";
    }
}
