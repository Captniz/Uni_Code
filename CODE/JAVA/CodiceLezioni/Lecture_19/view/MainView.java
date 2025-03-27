package Lecture_19.view;

import Lecture_19.controller.ClassroomController;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.BorderPane;

public class MainView extends BorderPane {

    // main view per il modello iniziale
    public MainView(StudentView cv) {
        this.setCenter(cv);
    }
    // main view per il modello esteso
    public MainView(ClassroomController cc){
        this.updateClassroom(cc.getCv());
        cc.setMv(this);

        // creiamo un bottone per ordinare per nome
        Button sbn = new Button("Ordina per Nome");
        sbn.setOnAction((e)->{
            cc.sortbyName();
        });
        this.setBottom(sbn);

//        this.addEventHandler(KeyEvent.ANY, (e) -> {
//            if( e.getCode() == KeyCode.S ){
//                cc.sortbyAge();
//            }
//            if( e.getCode() == KeyCode.N ){
//                cc.sortbyName();
//            }
//        });
    }

    // ci serve public questo metodo perche` viene chiamato
    // da altre parti del programma
    public void updateClassroom(ClassroomView cv){
        this.setCenter(cv);
    }
}
