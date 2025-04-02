package mutations;

import data.Statistics;
import interfaces.*;
import data.Attributes;

public class Strength implements StatMut,StdMut {
    public Strength() {
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
        stats.setStrength(stats.getStrength() + 2);
    }

    @Override
    public void removeStat(Statistics stats) {
        stats.setStrength(stats.getStrength() - 2);
    }

    @Override
    public String getName() {
        return "Strength";
    }
}
