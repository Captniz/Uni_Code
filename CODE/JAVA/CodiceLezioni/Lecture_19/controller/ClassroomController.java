package Lecture_19.controller;

import Lecture_19.model.Classroom;
import Lecture_19.model.comparators.*;
import Lecture_19.view.ClassroomView;
import Lecture_19.view.MainView;
import Lecture_19.view.StudentView;
import java.util.ArrayList;

public class ClassroomController {
    private Classroom c;
    private ClassroomView cv;
    private ArrayList<StudentController> asc;
    private MainView mv;

    // al classroom controller passiamo anche la lista di student controller
    // per gestire in modo uniforme azioni sulla lista
    // vediamo cosa fa handle
    public ClassroomController(Classroom r, ArrayList<StudentController> asr){
        this.c = r;
        this.asc = asr;
        this.cv = createClassroomView();
    }
    // perche` non possiamo passare mainview nel costruttore ?
    public void setMv(MainView m){
        this.mv = m;
    }

    // chiamiamo un comportamento su tutti gli studenti.
    // per farlo, chiamiamo quel comportamento sul controller,
    // che e` responsabile di fare il comportamento sul modello
    // e sulla view corrispondente
    public void ringiovanisciStudenti(){
        for (StudentController sc : asc) {
            sc.ringiovanisci();
        }
    }

    // per ordinare?
    // creo un comparator per studeni,
    // e un comparator per studentcontroller che si basa sul primo
    // poi fattorizzo tutto in una interfaccia mycomparator
    // cosi` da poter creare il metodo sort e non duplicare codice
    public void sortbyName(){
        this.sort(new StudentControllerNameComparator(new StudentNameComparator()));
    }
    public void sortbyAge(){
        this.sort(new StudentControllerAgeComparator(new StudentAgeComparator()));
    }
    private void sort(MyComparator mc){
        // sortiamo il modello
        this.c.sort(mc.getInnerComparator());
        // sortiamo i controller locali
        this.asc.sort(mc);
        // che usiamo per ricreare la view
        this.cv = createClassroomView();
        // e settarla nell'app
        this.mv.updateClassroom(this.cv);
    }
    private ClassroomView createClassroomView(){
        ArrayList<StudentView> asv = new ArrayList<>();
        for (StudentController sc: asc) {
            asv.add(sc.getSv());
        }
        return new ClassroomView(asv, this);
    }

    public ClassroomView getCv() { return cv; }
}
