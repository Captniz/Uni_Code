package Lecture_14;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.TilePane;
import javafx.stage.Stage;

public class Keyboard1 extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    int counter=0;
    public void start(Stage stage) {
        TilePane box = new TilePane();
        box.setHgap(50);
        Button b1 = new Button("Uno");
        box.getChildren().add(b1);
        EventHandler<ActionEvent> actionHandler = new EventHandler<ActionEvent>(){
            public void handle(ActionEvent t) {
                System.out.println((counter++) + ((Button)(t.getTarget())).getText());
            }
        };
        b1.addEventHandler(ActionEvent.ACTION, actionHandler);

        //SLIDE che si puo` premere da tastiera
        EventHandler<KeyEvent> keyEventHandler = new EventHandler<KeyEvent>(){
            public void handle(KeyEvent keyEvent) {
                if (keyEvent.getCode() == KeyCode.U) {
                    b1.fireEvent(new ActionEvent());
                    System.out.println(keyEvent.getSource() + " =>"+keyEvent.getTarget());
                }
            }
        };
        b1.addEventHandler(KeyEvent.KEY_PRESSED,keyEventHandler);
        Scene scene = new Scene(box, 400, 300);
        stage.setTitle("My JavaFX Application");
        stage.setScene(scene); stage.show();
    }
    // back
}
