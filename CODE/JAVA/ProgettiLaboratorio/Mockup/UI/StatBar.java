package UI;

import javafx.scene.layout.*;
import javafx.scene.text.*;
import javafx.geometry.Insets;

public class StatBar extends HBox {
    public int LVL;
    public int GP;
    Text text;
    
    public StatBar() {
        setPadding(new Insets(3,0,10,0));
        LVL = 10;
        GP = 0;
        text = new Text("Geraldo >> LVL: " + LVL + " | " + "GP: " + 0);

        getChildren().add(text);
    }

    public void updateStatBar() {
        text.setText("Geraldo >> LVL: " + LVL + " | " + "GP: " + GP);
    }


    public int getGP () {
        return GP;
    }

    public void setGP (int GP) {
        this.GP = GP;
        updateStatBar();
    }

    public int getLVL () {
        return LVL;
    }

    public void setLVL (int LVL) {
        this.LVL = LVL;
        updateStatBar();
    }
}