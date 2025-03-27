package Lecture_11;

import javafx.application.Application;
import javafx.scene.paint.Paint;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;

import javafx.scene.Group;
import javafx.scene.Scene;

public class Finestre extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        Text t=new Text(50, 100, "The quick brown fox jumps over the lazy dog");
        t.setTextAlignment(TextAlignment.RIGHT);
        t.setWrappingWidth(50);
        t.setFill(Paint.valueOf("GREEN"));
        Group g = new Group(t);
        Scene scene = new Scene(g);
        stage.setTitle("Titolo della finestra 1");
        stage.setScene(scene);
        // set stage dimension
        stage.setWidth(399);
        stage.setHeight(399);
        // set stage position
        stage.setX(1000);
        stage.setY(800);
        // make stage visible
        stage.show();

        Text t2=new Text(0, 20, "This is...\nanother window!");
        t2.setTextAlignment(TextAlignment.LEFT);
        t2.setFill(Paint.valueOf("RED"));
        t2.setFont(new Font(20));
        Group g2 = new Group(t2);
        Scene scene2 = new Scene(g2);
        scene2.setFill(Paint.valueOf("YELLOW"));
        Stage stage2 = new Stage();
        stage2.setTitle("Titolo della finestra 2");
        stage2.setScene(scene2);
        stage2.sizeToScene();
        stage2.setX(100);
        stage2.setY(80);
        stage2.show();

    }
}
