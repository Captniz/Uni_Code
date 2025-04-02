package mutations;

import data.Statistics;
import interfaces.*;
import data.Attributes;

public class Tollerance implements StatMut,StdMut {
    public Tollerance() {
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
        stats.setConstitution(stats.getConstitution() + 2);
    }

    @Override
    public void removeStat(Statistics stats) {
        stats.setConstitution(stats.getConstitution() - 2);
    }

    @Override
    public String getName() {
        return "Tollerance";
    }
}
