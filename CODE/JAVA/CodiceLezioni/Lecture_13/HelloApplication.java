package Lecture_13;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws IOException {
        Button b=new Button("click me");
        f(b);
        Group root=new Group(b);
        Scene scene = new Scene(root, 320, 240);
        stage.setTitle("Test!");
        stage.setScene(scene);
        stage.show();
    }
    private void f(Button b) {
        int counter=0;
        b.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                // SLIDE compilation error
//                counter++;
                // SLIDE ok, effectively final
                System.out.println(counter);
            }
        });
    }
}
