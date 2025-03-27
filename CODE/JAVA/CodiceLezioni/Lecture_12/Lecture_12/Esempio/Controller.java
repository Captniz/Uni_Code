package Lecture_12.Esempio;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.shape.Circle;

class Controller implements EventHandler<ActionEvent> { 
    int inc = 0;
    Circle c;

    public Controller(Circle ci) {
        c = ci;
    }

    @Override
    public void handle(ActionEvent event) {
        inc += 10;
//        c.setLayoutX(inc % 100);
//        c.setCenterX(inc % 100);
        c.setTranslateX(inc % 100);
        System.out.println(c.getLayoutX()+ " " + c.getTranslateX()+" "+c.getCenterX());
    }
}