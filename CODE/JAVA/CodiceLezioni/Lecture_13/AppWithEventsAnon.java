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

public class AppWithEventsAnon extends Application {
    Text text = null;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        text = new Text(10,50,"Non hai mai cliccato ");
        Button btn = new Button();
        btn.setText("Click me");

        EventHandler a = new EventHandler(){
            int counter=0;
            public void handle(Event t){
                updateText(++counter);
            }
        };
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