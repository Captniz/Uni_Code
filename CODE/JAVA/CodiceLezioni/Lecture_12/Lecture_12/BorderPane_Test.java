package Lecture_12;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class BorderPane_Test extends Application {
    @Override
    public void start(Stage stage){
        BorderPane layout=new BorderPane();
        Button top = new Button("Top");
        // allineamento interno delle componenti
        BorderPane.setAlignment(top, Pos.TOP_CENTER);
        // setta i componenti per-zona (non children)
        layout.setTop(top);
        layout.setBottom(new Button("Bottom"));
        layout.setLeft(new Button("Left"));
        layout.setRight(new Button("Right"));
        layout.setCenter(new Button("Center"));
        Scene scene = new Scene(layout);
        stage.setScene(scene); stage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}