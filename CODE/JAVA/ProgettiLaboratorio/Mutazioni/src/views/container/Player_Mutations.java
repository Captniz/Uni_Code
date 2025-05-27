package src.views.container;

import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import src.models.element.Player;
import src.models.element.mutations.Abs_Mutation;

public class Player_Mutations extends VBox {
    Player player;

    public Player_Mutations(Player player) {
        this.player = player;
        updateView();
    }

    public void updateView() {
        this.getChildren().clear();

        this.getChildren().add(new Label("Mutations:"));

        player.getMutations().forEach((key, val) -> {
            boolean empty = true;
            for (Abs_Mutation mut : val) {
                if (mut == null) {
                    continue;
                }
                Label mut_name = new Label(mut.getName());
                mut_name.setTextFill(mut.getType().getBgColor());
                this.getChildren().add(mut_name);
                empty = false;
            }

            if (empty) {
                Label mut_name = new Label("Empty");
                mut_name.setTextFill(key.getBgColor());
                this.getChildren().add(mut_name);
            }
        });
    }
}
