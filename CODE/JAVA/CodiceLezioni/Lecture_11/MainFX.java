package Lecture_11;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

// SLIDE
// SLIDE: highlights
public class MainFX extends Application {
    @Override

    // SLIDE: stage/scene/parent/node
    // non controlliamo lo stage e nemmeno la scene qui
    public void start(Stage primaryStage) throws Exception{
        Button button = new Button("Say Hello World!");
        button.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                System.out.println("Hello World!");
            }
        });
        StackPane root = new StackPane(button);
        primaryStage.setTitle("Hello World");
        //pero` aggiungiamo root, che e` un Pane, che contiene button, alla scene
        primaryStage.setScene(new Scene(root, 300, 275));
        primaryStage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
    // back
}