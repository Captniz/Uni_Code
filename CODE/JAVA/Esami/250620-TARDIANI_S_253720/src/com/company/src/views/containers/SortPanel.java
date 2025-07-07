package com.company.src.views.containers;

import com.company.src.views.View;
import com.company.src.views.elements.LifeSort;
import com.company.src.views.elements.NameSort;
import javafx.scene.layout.VBox;

public class SortPanel extends VBox implements View {
    NameSort nameSort;
    LifeSort lifeSort;

    public SortPanel(BroList broList) {
        super();
        nameSort = new NameSort(broList);
        lifeSort = new LifeSort(broList);
        updateView();
    }

    @Override
    public void updateView() {

        this.getChildren().clear();
        this.getChildren().addAll(nameSort, lifeSort);

    }
}
