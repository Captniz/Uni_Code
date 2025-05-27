package src.models.util;

import javafx.scene.paint.Color;

public enum MutTypes {
    COMBAT(Color.FIREBRICK),
    POTION(Color.GREENYELLOW),
    SPELL(Color.CADETBLUE),
    FREE(Color.GREY);

    private final Color bg_color;

    MutTypes(Color bg_color){
        this.bg_color = bg_color;
    }

    public Color getBgColor(){
        return bg_color;
    } 
}
