package Lecture_12;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class StackPane_Test extends Application {
//    TODO: toggle start to show
    @Override
//    public void start(Stage stage) {
//        StackPane layout = new StackPane();
//        // longer names
//        layout.getChildren().add(new Button("Unounouno"));
//        layout.getChildren().add(new Button("Duedue"));
//        layout.getChildren().add(new Button("Tre"));
//        Group root = new Group(layout);
//        Scene scene = new Scene(root); stage.setScene(scene);
//        stage.show();
//    }
    public void start(Stage stage){
        StackPane stack = new StackPane();
        Circle helpIcon = new Circle(15, 15, 15);
        helpIcon.setFill(Color.YELLOW);
        helpIcon.setStroke(Color.GREEN);
        Text helpText = new Text("?");
        helpText.setFont(Font.font("Verdana", FontWeight.BOLD, 18));
        helpText.setFill(Color.WHITE); helpText.setStroke(Color.RED);
        stack.getChildren().addAll(helpIcon, helpText);
        stack.setAlignment(Pos.CENTER);
        Scene scene = new Scene(stack);
        stage.setTitle("My JavaFX Application");
        stage.setScene(scene);
        stage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}