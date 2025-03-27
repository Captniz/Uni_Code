package Lecture_12;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class GridPane_Test extends Application {
    @Override
    public void start(Stage stage){
        // sofisticato
        GridPane layout = new GridPane();
        // dimensioni
        int width=100;
        int height=40;
        Scene scene = new Scene(layout, width, height, Color.BLANCHEDALMOND);
        // aggiungiamo direttamente al gridpane (non ai children)
        // le cose che aggiungiamo dicono la X e la Y (per debugging)
        layout.add(new Text("0, 0"), 0, 0);
        layout.add(new Button("0, 1"), 0, 1);
        layout.add(new Text("1, 1"), 1, 1);
        Rectangle r = new Rectangle(80,30);
        layout.add(r, 1, 2);
        layout.add(new Button("1, 3"), 1, 3);
        layout.add(new Button("2, 3"), 2, 3);
        layout.add(new Button("4, 0"), 4, 0);
        layout.add(new Text("4, 2"), 4, 2);
        // definiamo i vincoli di presentazione
        ColumnConstraints column1 = new ColumnConstraints(100);
        ColumnConstraints column2 = new ColumnConstraints();
        // nota: non tutti hanno senso!
        column2.setPercentWidth(40);
        column2.setHgrow(Priority.ALWAYS);
        // aggiungiamo tutti i vincoli
        layout.getColumnConstraints().addAll(column1, column2);
        stage.setScene(scene);
        stage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}