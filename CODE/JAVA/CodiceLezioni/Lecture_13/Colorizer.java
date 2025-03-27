package Lecture_13;

import javafx.application.Application;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.ColorPicker;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class Colorizer extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    public void start(final Stage stage) {
        final Circle circ = new Circle(40, 40, 30);
        final ColorPicker colorPicker1 = new ColorPicker(Color.BLACK);
        // convenience methods!
        colorPicker1.setOnAction(new EventHandler(){
            // colorPicker1.addEventHandler(ActionEvent.ACTION, new EventHandler() {
            @Override
            public void handle(Event t) {
                System.out.println(t.getEventType());
                circ.setFill(colorPicker1.getValue()); }}
        );
        Scene scene = new Scene(new HBox(20), 400, 100);
        HBox box = (HBox) scene.getRoot();
        box.getChildren().addAll(circ,colorPicker1);
        stage.setScene(scene);
        stage.show(); }
}
