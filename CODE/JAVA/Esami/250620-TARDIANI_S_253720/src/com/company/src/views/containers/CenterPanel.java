package com.company.src.views.containers;

import com.company.src.views.View;
import javafx.scene.layout.HBox;


public class CenterPanel extends HBox implements View {
    SortPanel sortings;
    GraphPanel graph;

    public CenterPanel(SortPanel sortings, GraphPanel graph) {
        this.sortings = sortings;
        this.graph = graph;

        this.getChildren().add(sortings);
        this.getChildren().add(graph);
    }

    @Override
    public void updateView() {
        sortings.updateView();
    }
}
