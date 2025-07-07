package com.company.src.views.elements;

import com.company.src.models.elements.brotypes.AbsBro;
import com.company.src.views.View;
import javafx.scene.control.Label;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;

public class InfoBox extends StackPane implements View {
    AbsBro bro;
    private final int WIDTH = 130;
    private final int HEIGHT = 90;

    public InfoBox(AbsBro bro) {
        super();
        this.setPrefSize(WIDTH, HEIGHT);
        this.bro=bro;
        updateView();
    }

    @Override
    public void updateView() {
        backgroundProperty().set(new Background(new BackgroundFill(bro.getType().getColor(), null, null)));
        this.getChildren().clear();
        this.getChildren().add(new InfoShow());
    }

    public AbsBro getBro() {
        return bro;
    }

    private class InfoShow extends VBox implements View {

        private InfoShow() {
            super();
            updateView();
        }

        @Override
        public void updateView() {
            this.getChildren().clear();
            this.getChildren().add(new Label(bro.getName()+" "+bro.getLevel()));
            this.getChildren().add(new Label(bro.getHp()+" "+bro.getType().getSpeed()));
            this.getChildren().add(new Label(bro.getAttack().getName()+", "+bro.getAttack().getDamage()));
        }
    }
}