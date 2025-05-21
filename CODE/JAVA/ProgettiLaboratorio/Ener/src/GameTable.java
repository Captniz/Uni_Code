package src;

import javafx.geometry.NodeOrientation;
import javafx.geometry.Pos;
import javafx.scene.layout.BorderPane;

import src.views.*;

public class GameTable extends BorderPane{
    Player player1;
    Player player2;
    PlayerInvocView invocMain;
    PlayerInvocView invocSecond;
    AbsListEnergyView energyMain;
    AbsListEnergyView energySecond;

    public GameTable() {
        
        // ########## BASE GAME SETUP // DO NOT TOUCH #########
        // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

        // Creating players
        player1 = new Player();
        player2 = new Player();

        // Creating energies
        player1.addMultipleEnergy(2, 0, 1, 2);
        player2.addMultipleEnergy(0, 2, 1, 1);

        // Creating invocations
        player1.addInvocation(Compendium.invocations.get(0));
        player1.addInvocation(Compendium.invocations.get(1));
        player1.addInvocation(Compendium.invocations.get(2));
        
        player2.addInvocation(Compendium.invocations.get(3));
        player2.addInvocation(Compendium.invocations.get(4));
        player2.addInvocation(Compendium.invocations.get(5));
        
        // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        // ########## BASE GAME SETUP // DO NOT TOUCH #########

        // Creating views
        invocSecond = new PlayerInvocView(player2);
        invocMain = new MainPlayerInvocView(player1, invocSecond, this);
        
        energyMain = new MainEnergyView(player1, invocMain);
        
        invocSecond.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
        energySecond = new SecondaryEnergyView(player2);
        energySecond.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
        energySecond.setAlignment(Pos.BOTTOM_CENTER);

        this.setBottom(invocMain);
        this.setLeft(energyMain);
        this.setTop(invocSecond);
        this.setRight(energySecond);
    }

    public void changeTurn(){
        this.getChildren().clear();

        Player temp = player1;
        player1 = player2;
        player2 = temp;

        invocSecond = new PlayerInvocView(player2);
        invocMain = new MainPlayerInvocView(player1, invocSecond, this);
        
        energyMain = new MainEnergyView(player1, invocMain);
        
        invocSecond.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
        energySecond = new SecondaryEnergyView(player2);
        energySecond.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
        energySecond.setAlignment(Pos.BOTTOM_CENTER);

        this.setBottom(invocMain);
        this.setLeft(energyMain);
        this.setTop(invocSecond);
        this.setRight(energySecond);
        
    }
}
