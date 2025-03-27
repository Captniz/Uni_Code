package Lecture_13;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.scene.Group;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.event.EventHandler;
import javafx.scene.Scene;

public class LisMul extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage stage) {
        Button btn = new Button();
        btn.setText("Click me");
        OListener o = new OListener();
        EListener e = new EListener();
        btn.addEventHandler(ActionEvent.ACTION, o);
        btn.addEventHandler(ActionEvent.ACTION, e);
        Group root = new Group(btn);
        Scene scene = new Scene(root, 300, 250);
        stage.setScene(scene);
        stage.show();
    }
}

class OListener implements EventHandler{
    public void handle(Event t) {
        System.out.println(t); }
}

class EListener implements EventHandler{
    public void handle(Event t) {
        System.err.println(t); }
}