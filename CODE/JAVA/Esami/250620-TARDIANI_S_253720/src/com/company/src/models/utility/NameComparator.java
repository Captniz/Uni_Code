package com.company.src.models.utility;

import com.company.src.models.elements.brotypes.AbsBro;

import java.util.Comparator;

public class NameComparator implements Comparator<AbsBro> {

    @Override
    public int compare(AbsBro o1, AbsBro o2) {
        return o1.getName().compareTo(o2.getName());
    }
}
