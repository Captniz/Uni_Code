package Lecture_14;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class AppWithEvents extends Application {
    Text text = null;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        text = new Text(10,50,"Non hai mai cliccato ");
        Button b = new Button("PLUS");
        // dichiariamo un event handler su eventi di tipo KeyEvent
        EventHandler<KeyEvent> keyEventHandler = new EventHandler<KeyEvent>() {
        @Override
        public void handle(KeyEvent e) {
            // questo viene fatto sempre
            text.setText("Hai cliccato un tasto");
            // controlliamo di aver premuto +
            if (e. getCharacter().equals("+")) {
                System.out.println("Button + pressed");
            }
            // SLIDE gestire la pressione dei tasti
            // TODO
            if (e.getCode() == KeyCode.U){
                System.out.println(" U ");
            }
            // SLIDE gestire
            }
            // back
        };
        b.addEventHandler(KeyEvent.KEY_TYPED,keyEventHandler);
        Group root = new Group(b);
        root.getChildren().add(text);
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
    public void updateText(int n){
        text.setText("Hai cliccato " + n +" volte");
    }

}