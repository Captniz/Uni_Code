package src.views;

import javafx.scene.layout.HBox;
import javafx.geometry.Insets;

import src.Invocation;
import src.Player;

public class PlayerInvocView extends HBox{
    
    Player player;
    
    public PlayerInvocView(Player player) {
        super();

        this.player = player;
        updateVisuals();
    }

    private void updateVisuals() {
        this.getChildren().clear();
        for (Invocation invoc : player.getInvocations()) {
            if (invoc.getPV() <= 0) {
                player.getInvocations().remove(invoc);
                continue;
            }
    
            InvocationView invocView = new InvocationView(invoc);
            HBox.setMargin(invocView, new Insets(0, 0, 0, 10));
            this.getChildren().add(invocView);
        }
    }

    public void updateInvocations(Player player) {
        this.player = player;
        this.updateVisuals();
    }

    public void updateInvocations() {
        this.updateVisuals();
    }

    public Player getPlayer() {
        return player;
    }
}
