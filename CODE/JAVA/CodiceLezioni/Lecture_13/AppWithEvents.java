package Lecture_13;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.scene.Group;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.event.EventHandler;
import javafx.event.Event;

public class AppWithEvents extends Application {
    Text text = null;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        text = new Text(10,50,"Non hai mai cliccato ");
        Button btn = new Button();
        btn.setText("Click me");
        ExtListener a = new ExtListener(this);
        btn.addEventHandler(ActionEvent.ACTION, a);
        Group root = new Group(btn);
        root.getChildren().add(text);
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void updateText(int n){
        text.setText("Hai cliccato " + n +" volte");
    }
}

class ExtListener implements EventHandler {
    AppWithEvents awe = null;
    int counter = 0;

    ExtListener(AppWithEvents a){ awe = a; }

    public void handle(Event t) {
        awe.updateText(++counter);
    }
}