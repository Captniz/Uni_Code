package src.models;

import java.util.Comparator;

public class CostComparator implements Comparator<Fan> {

    @Override
    public int compare(Fan fan1, Fan fan2) {
        int cost_compare = Integer.compare(fan2.getCosto(), fan1.getCosto());
        return cost_compare != 0 ? cost_compare : Integer.compare(fan1.getTipo().getPriority(), fan2.getTipo().getPriority());
    }
}
