package Lecture_19.controller;

import Lecture_19.model.Student;
import Lecture_19.view.StudentView;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.control.TextInputDialog;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;

public class StudentController implements EventHandler<Event> {
    private Student st;
    private StudentView sv;

    public StudentController(Student s){
        this.st = s;
        StudentView v = new StudentView(s.getAge(), s.getName());
        this.sv = v;
        // controller come event handler, per action e key
        sv.getNamebutton().addEventHandler(ActionEvent.ACTION,this);
        sv.getNamebutton().addEventHandler(KeyEvent.KEY_PRESSED,this);
    }

    public StudentView getSv() { return sv; }
    public Student getSt() { return st; }

    @Override
    public void handle(Event event) {
        if (event instanceof ActionEvent){
            this.logic();
        }
        if (event instanceof KeyEvent ){
            if( ((KeyEvent)event).getCode() == KeyCode.U ){
                this.logic();
            }
        }
    }
    private void logic(){
        TextInputDialog tid = new TextInputDialog();
        tid.showAndWait();
        String newname = tid.getEditor().getText();
        // chiamiamo l'effetto sul model
        st.setName(newname);
        // e poi aggiorniamo la view
        sv.getNamebutton().setText(newname);
    }

    // questo metodo lo vediamo dopo, con classroomcontroller
    public void ringiovanisci(){
        // chiamiamo l'effetto sul model
        st.ringiovanisci();
        // e poi aggiorniamo la view
        sv.getAgetext().setText(st.getAge()+"");
    }
}
