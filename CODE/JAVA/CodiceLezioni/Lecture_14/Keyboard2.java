package Lecture_14;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.event.EventTarget;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.TilePane;
import javafx.stage.Stage;

public class Keyboard2 extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    int counter=0;
    public void start(Stage stage) {
        TilePane box = new TilePane();
        box.setHgap(50);
        Button b1 = new Button("Uno");
        Button b2 = new Button("Due");
        box.getChildren().addAll(b1,b2);
        Scene scene = new Scene(box, 400, 300);
        stage.setTitle("My JavaFX Application");
        stage.setScene(scene);

        EventHandler<ActionEvent> actionHandler = new EventHandler<ActionEvent>(){
            public void handle(ActionEvent t) {
                System.out.println((counter++) + ((Button)(t.getTarget())).getText());
            }
        };
        b1.addEventHandler(ActionEvent.ACTION, actionHandler);
        b2.addEventHandler(ActionEvent.ACTION, actionHandler);

        // SLIDE selezione
        // SLIDE generazione e propagazione 2x
//        EventHandler<KeyEvent> keyEventHandler = new EventHandler<KeyEvent>(){
//            public void handle(KeyEvent keyEvent) {
//                if (keyEvent.getCode() == KeyCode.U) {
//                    b1.fireEvent(new ActionEvent());
//                    System.out.println(keyEvent.getSource() + " =>"+keyEvent.getTarget());
//                }
//            }
//        };
//        b1.addEventHandler(KeyEvent.KEY_PRESSED,keyEventHandler);
//        b2.addEventHandler(KeyEvent.KEY_PRESSED,keyEventHandler);
        // TODO commenta l'handler di sopra
        // TODO decommenta quello sotto
        // SLIDE vediamo se e` vero 2x

        EventHandler handler = new EventHandler<ActionEvent>() {
            public void handle(ActionEvent t) {
                EventTarget target = t.getTarget();
                Object source = t.getSource();
                String id=null;
                if (source instanceof Node) {
                    id = ((Node) source).getId();
                } else if (source instanceof Stage) {
                    id="STAGE";
                } else if (source instanceof Scene) {
                    id="SCENE";
                } else
                    System.out.println("Unrecognized object: "+source);
                System.out.println("HANDLER: "+id+" "+source+" =>"+target); }
        };
        box.setId("TILEPANE");
        b1.setId("BUTTON1");
        b2.setId("BUTTON2");
        stage.addEventHandler(ActionEvent.ACTION, handler);
        scene.addEventHandler(ActionEvent.ACTION, handler);
        box.addEventHandler(ActionEvent.ACTION, handler);
        b1.addEventHandler(ActionEvent.ACTION, handler);
        b2.addEventHandler(ActionEvent.ACTION, handler);

        // SLIDE come risolve
        EventHandler<KeyEvent> keyEventHandler = new EventHandler<KeyEvent>() {
            public void handle(KeyEvent keyEvent) {
                if (keyEvent.getCode() == KeyCode.U) {
                    b1.fireEvent(new ActionEvent());
                    System.out.println(keyEvent.getSource() + " =>" + keyEvent.getTarget());
                }
                // SLIDE gestire ambedue i bottoni
                // per il bottone Due, premere D, non U!
                switch (keyEvent.getCode()) {
                    case U:
                    case DIGIT1:
                        b1.fireEvent(new ActionEvent());
                        // SLIDE spostando il focus
                        b1.requestFocus();
                        break;
                    case D:
                    case DIGIT2:
                        b2.fireEvent(new ActionEvent());
                        b2.requestFocus();
                        break;
                }
            }
        };
        stage.addEventHandler(KeyEvent.KEY_PRESSED,keyEventHandler);

        stage.show();
    }
}
