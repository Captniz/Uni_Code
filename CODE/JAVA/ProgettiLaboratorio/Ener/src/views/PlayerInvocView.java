package src.views;

import javafx.scene.layout.HBox;

import java.util.LinkedList;

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
            InvocationView invocView = new InvocationView(invoc);
            HBox.setMargin(invocView, new Insets(0, 0, 0, 10));
            this.getChildren().add(invocView);
        }
    }

    public void checkInvocHealth(){
        LinkedList<Invocation> invocs = player.getInvocations();
        int len = invocs.size();
        
        for (int i = 0; i < len; i++) {
            Invocation invoc = invocs.get(i);
            if (invoc.getPV() <= 0) {
                invocs.remove(i);
                len--;
                i--;
            }
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
