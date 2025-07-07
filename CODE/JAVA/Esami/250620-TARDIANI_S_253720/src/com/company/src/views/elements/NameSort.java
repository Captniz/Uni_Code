package com.company.src.views.elements;

import com.company.src.models.utility.NameComparator;
import com.company.src.views.containers.BroList;
import javafx.scene.control.Button;

public class NameSort extends Button {
    public NameSort(BroList broList) {
        super("Ordina per nome");
        this.setOnMouseClicked(event -> {
            broList.sort(new NameComparator());
        });
    }
}
