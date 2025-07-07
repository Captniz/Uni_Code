package com.company.src.views.containers;

import com.company.src.views.View;
import com.company.src.views.elements.BigBroView;
import javafx.scene.layout.VBox;

public class MainContainer extends VBox implements View {
    BroList broList;
    CenterPanel centerPanel;
    EnemyBar enemyBar;

    public MainContainer() {
        super();
        enemyBar = new EnemyBar();
        GraphPanel graph = new GraphPanel(enemyBar);
        broList = new BroList(graph);
        centerPanel = new CenterPanel(new SortPanel(broList), graph);

        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().clear();
        this.getChildren().add(broList);
        this.getChildren().add(centerPanel);
        this.getChildren().add(enemyBar);

        broList.updateView();
        centerPanel.updateView();
        enemyBar.updateView();
    }
}
