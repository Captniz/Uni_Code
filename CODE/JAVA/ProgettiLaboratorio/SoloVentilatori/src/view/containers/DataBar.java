package src.view.containers;

import javafx.scene.layout.HBox;
import javafx.scene.control.Label;
import javafx.geometry.Insets;
import javafx.scene.Node;

import src.models.UserData;

public class DataBar extends HBox{
    private UserData userData;

    public DataBar(UserData userData) {
        this.userData = userData;
        updateDataBar();
    }

    public void updateDataBar() {
        this.getChildren().clear();
        this.getChildren().add(new Label("Captiale: " + userData.getMoney()));
        this.getChildren().add(new Label("Spesa Mensile: " + userData.getMonthly_cost()));
        this.getChildren().add(new Label("Mesi Trascorsi: " + userData.getMonth()));

        for (Node child : this.getChildren()) {
            HBox.setMargin(child, new Insets(0,5,0,0));
        }
    }
}
