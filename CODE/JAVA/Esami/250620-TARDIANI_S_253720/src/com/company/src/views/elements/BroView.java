package com.company.src.views.elements;

import com.company.src.models.elements.brotypes.AbsBro;
import com.company.src.views.View;
import javafx.geometry.Insets;
import javafx.scene.control.Label;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.StackPane;

public class BroView extends StackPane implements View {
    private AbsBro bro;
    private final int WIDTH = 70;
    private final int HEIGHT = 70;
    public static final int MARGIN = 5;

    public BroView(AbsBro bro) {
        super();
        this.setPrefSize(WIDTH, HEIGHT);
        this.bro=bro;
        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().clear();
        this.backgroundProperty().set(new Background(new BackgroundFill(bro.getType().getColor(),null,null)));
        this.getChildren().add(new Label(bro.getName()));
    }

    public AbsBro getBro() {
        return bro;
    }
}
