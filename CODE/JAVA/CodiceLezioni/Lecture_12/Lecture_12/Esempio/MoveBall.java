package Lecture_12.Esempio;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class MoveBall extends Application {
    @Override
    public void start(Stage primaryStage) {
        Circle c = new Circle(200, 200, 10);
        c.setFill(Color.AQUAMARINE);
        Button btn = new Button();
        btn.setText("Move circle");
        btn.setOnAction(new Controller(c));
        VBox root = new VBox();
        root.getChildren().addAll(c, btn);
        Scene scene = new Scene(root, 100, 50);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
