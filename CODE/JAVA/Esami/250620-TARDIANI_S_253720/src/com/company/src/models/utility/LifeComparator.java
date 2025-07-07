package com.company.src.models.utility;

import com.company.src.models.elements.brotypes.AbsBro;

import java.util.Comparator;

public class LifeComparator implements Comparator<AbsBro> {

    @Override
    public int compare(AbsBro o1, AbsBro o2) {
        if (o1.getHp() > o2.getHp()) {
            return 1;
        } else if (o1.getHp() < o2.getHp()) {
            return -1;
        }
        return 0;
    }
}
