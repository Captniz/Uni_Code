package Lecture_14.EsempioCalc;

import javafx.scene.control.TextField;

class NonEditableTextField extends TextField {

    NonEditableTextField(String s) {
        super(s);
        this.setEditable(false);
    }
}