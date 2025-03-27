package Lecture_12;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class AnchorPane_Test extends Application {
    @Override
    public void start(Stage stage) {
        AnchorPane layout = new AnchorPane();
        Button buttonSave = new Button("Save");
        Button buttonCancel = new Button("Cancel");
        HBox hb = new HBox();
        // setto distanziamenti interni all'HBox
        hb.setPadding(new Insets(0, 10, 10, 10));
        hb.setSpacing(10);
        // metto i bottoni nell' Hbox
        hb.getChildren().addAll(buttonSave, buttonCancel);
        // creo il rettangolo
        Rectangle r = new Rectangle(100, 100);
        // aggiungo il rettangolo e i bottoni all'anchor pane
        layout.getChildren().addAll(r, hb);
        // setto le ancore per-node, i valori sono pixels
        layout.setBottomAnchor(hb, 8.0);
        layout.setRightAnchor(hb, 5.0);
        layout.setTopAnchor(r, 10.0);
        layout.setLeftAnchor(r, 50.0);
        Scene scene = new Scene(layout);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}