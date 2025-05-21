package src.views;

import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import src.GameTable;
import src.Invocation;
import src.Player;

public class MainPlayerInvocView extends PlayerInvocView {
    PlayerInvocView opponentInvocView;
    GameTable gameTable;
    
    public MainPlayerInvocView(Player player, PlayerInvocView opponentInvocView, GameTable gameTable) {
        super(player);
        this.opponentInvocView = opponentInvocView;
        this.gameTable = gameTable;

        for (Node node : this.getChildren()) {
            node.setOnMouseClicked(new MouseEventHandler(opponentInvocView,this));
        }
    }

    @Override 
    public void updateInvocations() {
        super.updateInvocations();
        for (Node node : this.getChildren()) {
            node.setOnMouseClicked(new MouseEventHandler(opponentInvocView,this));
        }
    }

    class MouseEventHandler implements EventHandler<MouseEvent> {
        PlayerInvocView opponentInvocView;
        MainPlayerInvocView thisInvocView;

        public MouseEventHandler(PlayerInvocView opponentInvocView, MainPlayerInvocView thisInvocView) {
            this.opponentInvocView = opponentInvocView;
            this.thisInvocView = thisInvocView;
        }
        
        @Override
        public void handle(MouseEvent event) {
            if(event.getSource() instanceof InvocationView){
                InvocationView invocView = (InvocationView) event.getSource();
                Invocation invoc = invocView.getInvocation();

                if (invoc.getAssignedEnergy() >= invoc.getAttack().getEnergyCost()) {
                    invoc.setAssignedEnergy(invoc.getAssignedEnergy() - invoc.getAttack().getEnergyCost());
                    
                    if (invoc.getInvocationType() == Invocation.InvocationType.SUPREME) {
                        for (Invocation oppInvoc : opponentInvocView.getPlayer().getInvocations()) {
                            oppInvoc.damageFor(invoc.getAttack().getDamage(), invoc.getType());
                        }
                    }else{
                        opponentInvocView.getPlayer().getInvocations().get(0).damageFor(invoc.getAttack().getDamage(), invoc.getType());
                    }

                    opponentInvocView.checkInvocHealth();

                    // ######## Game checks
    
                    // Check if opponent has no invocations and terminate game
                    if (opponentInvocView.getPlayer().getInvocations().isEmpty()) {
                        System.out.println("Game Over: You win!");
                        Alert alert = new Alert(Alert.AlertType.INFORMATION);
                        alert.setTitle("Game Over");
                        alert.setContentText("You win!");
                        alert.showAndWait();
                        System.exit(0);
                    }
    
                    // Invert table
                    gameTable.changeTurn();
                    
                }else{
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error");
                    alert.setContentText("Not enough energy to attack");
                    alert.showAndWait();
                    return;
                }
                
                thisInvocView.updateInvocations();
                opponentInvocView.updateInvocations();
            }
        }
    }
}
