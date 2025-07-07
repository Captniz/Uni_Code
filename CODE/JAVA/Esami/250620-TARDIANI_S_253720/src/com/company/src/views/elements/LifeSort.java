package com.company.src.views.elements;

import com.company.src.models.utility.LifeComparator;
import com.company.src.views.containers.BroList;
import javafx.scene.control.Button;

public class LifeSort  extends Button {
    public LifeSort(BroList broList) {
        super("Ordina per vita");
        this.setOnMouseClicked(event -> {
            broList.sort(new LifeComparator());
        });
    }
}
