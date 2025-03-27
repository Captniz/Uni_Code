package Lecture_13;

import javafx.application.Application;
import javafx.event.Event;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.event.EventHandler;
import javafx.scene.Scene;

public class Layout1 extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage stage) {
        StackPane layout = new StackPane();
        EventHandler<Event> eh = new EventHandler<Event>() {
            public void handle(Event event) {
                Button source = (Button) event.getSource();
                System.out.println("Ricevuto da " + source.getText() + ": " + event.getEventType());
            }};
        Button b1 = new Button("Unoo");
        Button b2 = new Button("Due");
        Button b3 = new Button("Tre");
        // b3.setMouseTransparent(true);
        b1.addEventHandler(Event.ANY, eh);
        b2.addEventHandler(Event.ANY, eh);
        b3.addEventHandler(Event.ANY, eh);
        layout.getChildren().addAll(b1,b2,b3);
        Scene scene = new Scene(layout);
        stage.setScene(scene);
        stage.show();
    }
}
