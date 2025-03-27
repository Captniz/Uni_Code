package Lecture_14;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.event.EventTarget;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.TilePane;
import javafx.stage.Stage;

public class Keyboard2FilterSuper extends Application {

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

        SuperHandler filter = new SuperHandler () {
            public void handle(ActionEvent t) {
                super.handle(t);
                System.out.println("FILTER:"+id+" "+source+" ==> "+target);
            } };
        SuperHandler handler = new SuperHandler() {
            public void handle(ActionEvent t) {
                super.handle(t);
                System.out.println("HANDLER:"+id+" "+source+" ==> "+target); }
        };
        SuperHandler cutter = new SuperHandler() {
            public void handle(ActionEvent t) {
                super.handle(t);
                System.out.println("CUTTER:"+id+" "+source+" ==> "+target);
                t.consume();
            }
        };
        box.setId("TILEPANE");
        b1.setId("BUTTON1");
        b2.setId("BUTTON2");

//        stage.addEventFilter(ActionEvent.ACTION, filter);
//        stage.addEventHandler(ActionEvent.ACTION, handler);
//        scene.addEventFilter(ActionEvent.ACTION, filter);
//        scene.addEventHandler(ActionEvent.ACTION, handler);
//        box.addEventFilter(ActionEvent.ACTION, cutter);
//        box.addEventHandler(ActionEvent.ACTION, handler);
//        b1.addEventFilter(ActionEvent.ACTION, cutter);
//        b1.addEventHandler(ActionEvent.ACTION, handler);
        // TODO commentare il blocco sopra o sotto
        stage.addEventFilter(ActionEvent.ACTION, filter);
        stage.addEventHandler(ActionEvent.ACTION, handler);
        scene.addEventFilter(ActionEvent.ACTION, filter);
        scene.addEventHandler(ActionEvent.ACTION, handler);
        box.addEventFilter(ActionEvent.ACTION, filter);
        box.addEventHandler(ActionEvent.ACTION, cutter);
        b1.addEventFilter(ActionEvent.ACTION, filter);
        b1.addEventHandler(ActionEvent.ACTION, cutter);

        stage.show();
    }
}

class SuperHandler implements EventHandler<ActionEvent>{
    protected EventTarget target;
    protected Object source;
    protected String id;
    @Override
    public void handle(ActionEvent t) {
        target = t.getTarget();
        source = t.getSource();
        id = null;
        if (source instanceof Node) {
            id = ((Node) source).getId();
        } else if (source instanceof Stage) {
            id="STAGE";
        } else if (source instanceof Scene) {
            id="SCENE";
        } else
            System.out.println("Unrecognized object: "+source);
    }
}