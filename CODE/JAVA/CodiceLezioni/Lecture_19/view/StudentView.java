package Lecture_19.view;

import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;

public class StudentView extends HBox {
    private Button namebutton;
    private Text agetext;

    // la student view e` semplice:
    // un bottone col nome e un textfield con l'eta`
    public StudentView(int age, String name){
        this.namebutton = new Button();
        namebutton.setText(name);
        this.agetext = new Text();
        agetext.setText(age+"");

        this.getChildren().add(namebutton);
        this.getChildren().add(agetext);
    }

    public Button getNamebutton() { return namebutton; }
    public Text getAgetext() { return agetext; }
}
