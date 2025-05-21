package src.models;

import java.util.Comparator;

public class TypeComparator implements Comparator<Fan> {

    @Override
    public int compare(Fan fan1, Fan fan2) {
        int type_compare = Integer.compare(fan1.getTipo().getPriority(), fan2.getTipo().getPriority());
        return type_compare != 0 ? type_compare : Integer.compare(fan2.getCosto(), fan1.getCosto());
    }
}
