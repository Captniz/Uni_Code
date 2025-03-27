package Lecture_13;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class AppWithEventsImplements extends Application implements EventHandler<ActionEvent>{
    Text text = null;
    int counter= 0;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        text = new Text(10,50,"Non hai mai cliccato ");
        Button btn = new Button();
        btn.setText("Click me");
        // this diventa l'handlers
        btn.addEventHandler(ActionEvent.ACTION, this);
//         btn.setOnAction(this);
        // SLIDE convenience methods
        // decommenta sopra
        // SLIDE convenience
        Group root = new Group(btn);
        root.getChildren().add(text);
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void updateText(int n){
        text.setText("Hai cliccato " + n +" volte");
    }
    public void handle(ActionEvent t) {
        updateText(++counter);
    }
}