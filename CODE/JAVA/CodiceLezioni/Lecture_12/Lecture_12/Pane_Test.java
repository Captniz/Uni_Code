package Lecture_12;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class Pane_Test extends Application {
    @Override
    public void start(Stage primaryStage){
        primaryStage.setTitle("Hello World!");
        Button btn = new Button();
        btn.setText("'Hello World'");
        // posizionamento assoluto
        btn.setLayoutX(250);
        btn.setLayoutY(220);
        Pane pane= new Pane();
        pane.getChildren().add(btn);
        Group root = new Group(pane);
        primaryStage.setScene(new Scene(root, 300, 250));
        primaryStage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}