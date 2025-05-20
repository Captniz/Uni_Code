package src.views;

import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import src.Invocation;
import src.Player;

public class MainPlayerInvocView extends PlayerInvocView {
    PlayerInvocView opponentInvocView;
    
    public MainPlayerInvocView(Player player, PlayerInvocView opponentInvocView) {
        super(player);
        this.opponentInvocView = opponentInvocView;
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
            System.out.println("Clicked on " + event.getTarget());
            if(event.getTarget() instanceof InvocationView){
                InvocationView invocView = (InvocationView) event.getTarget();
                Invocation invoc =invocView.getInvocation();

                if (invoc.getAssignedEnergy() >= invoc.getAttack().getEnergyCost()) {
                    invoc.setAssignedEnergy(invoc.getAssignedEnergy() - invoc.getAttack().getEnergyCost());
                    
                    
                    if (invoc.getInvocationType() == Invocation.InvocationType.SUPREME) {
                        for (Invocation oppInvoc : opponentInvocView.getPlayer().getInvocations()) {
                            oppInvoc.damageFor(invoc.getAttack().getDamage(), invoc.getType());
                        }
                    }else{
                        opponentInvocView.getPlayer().getInvocations().get(0).damageFor(invoc.getAttack().getDamage(), invoc.getType());
                    }
                }else{
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error");
                    alert.setContentText("Not enough energy to attack");
                }

                thisInvocView.updateInvocations();
                opponentInvocView.updateInvocations();
            }
        }
    }
}
