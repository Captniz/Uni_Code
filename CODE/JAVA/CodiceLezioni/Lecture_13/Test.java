package Lecture_13;

import javafx.application.Application;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class Test extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage stage) {
        Button btn = new Button();
        btn.setText("Click me");
        Listener a = new Listener();
        btn.addEventHandler(Event.ANY, a);
        Group root = new Group(btn);
        Scene scene = new Scene(root, 300, 250);
        stage.setScene(scene);
        stage.sizeToScene();
        stage.show();
    }
}

class Listener implements EventHandler {
    int counter=0;
    public void handle(Event t) {
        System.out.println(++counter+" Ricevuto un evento di tipo " +t.getEventType());
    }
}
