package Lecture_19.view;

import Lecture_19.controller.ClassroomController;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.VBox;
import java.util.ArrayList;

public class ClassroomView extends VBox {
    private Button ringiovaniscibutton;

    public ClassroomView(ArrayList<StudentView> asv, ClassroomController cc){
        for (StudentView sv: asv) {
            this.getChildren().add(sv);
        }
        this.ringiovaniscibutton = new Button("Ringiovanisci");
        this.ringiovaniscibutton.setOnAction( (e) -> {
            cc.ringiovanisciStudenti();
        } );
        this.getChildren().add(ringiovaniscibutton);

        // commentare dopo che e` decommentato in mainview
        this.addEventHandler(KeyEvent.ANY, (e) -> {
            if( e.getCode() == KeyCode.S ){
                cc.sortbyAge();
            }
            if( e.getCode() == KeyCode.N ){
                cc.sortbyName();
            }
        });
    }
}
