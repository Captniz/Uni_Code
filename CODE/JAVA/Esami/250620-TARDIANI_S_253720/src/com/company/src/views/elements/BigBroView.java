package com.company.src.views.elements;

import com.company.src.models.elements.brotypes.AbsBro;
import com.company.src.views.View;
import com.company.src.views.containers.BroList;
import javafx.geometry.Insets;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

public class BigBroView extends HBox implements View {
    private InfoBox infoBox;
    private AddLevel addLevel;
    private final int WIDTH = 170;
    private final int HEIGHT = 90;

    public BigBroView(AbsBro bro) {
        super();
        this.infoBox = new InfoBox(bro);
        this.addLevel = new AddLevel();
        this.setMaxSize(WIDTH, HEIGHT);
        HBox.setMargin(infoBox, new Insets(0,0,0,20));
        this.getChildren().addAll(infoBox,addLevel);
        updateView();
    }

    @Override
    public void updateView() {
        infoBox.updateView();
    }

    class AddLevel extends Button {
        public AddLevel() {
            super("+");
            this.setMaxSize(20,20);
            this.setOnMouseClicked(event -> {
                try {
                    infoBox.getBro().levelUp();
                }catch (AbsBro.MaxLevel e){
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Max Level");
                    alert.setHeaderText("Non è possibile eccedere il livello 11");
                    alert.showAndWait();
                    e.printStackTrace();
                }
                infoBox.updateView();
            });
        }
    }
}
