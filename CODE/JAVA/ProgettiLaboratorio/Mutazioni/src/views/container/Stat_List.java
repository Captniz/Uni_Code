package src.views.container;

import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import src.models.element.Player;
import src.models.element.spells.Abs_Spell;


public class Stat_List extends VBox{
    private Player player;    

    public Stat_List(Player player){
        this.player = player;
        updateView();
    }

    public void updateView(){
        this.getChildren().clear();

        this.getChildren().addAll(
            new Label("Lvl: " + player.getLevel()),
            new Label("Str: " + player.getStrength()),
            new Label("Vel: " + player.getVelocity()),
            new Label(""),
            new Label("Tol: " + player.getTolerance()),
            new Label(""),
            new Label("Spells: ")
        );
        for (Abs_Spell spell : player.getSpells()) {
            this.getChildren().add(new Label(
                spell.getName()
            ));
        }
    }
}
