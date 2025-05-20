package src;

import javafx.geometry.NodeOrientation;
import javafx.geometry.Pos;
import javafx.scene.layout.BorderPane;

import src.views.*;

public class GameTable extends BorderPane{
    Player player1;
    Player player2;
    PlayerInvocView playerMain;
    PlayerInvocView playerSecond;
    AbsListEnergyView energyMain;
    AbsListEnergyView energySecond;

    public GameTable() {
        // Creating players
        player1 = new Player();
        player2 = new Player();

        // Creating energies
        player1.addMultipleEnergy(2, 0, 1, 2);
        player2.addMultipleEnergy(0, 2, 1, 1);

        // Creating invocations
        player1.addInvocation(Compendium.invocations.get(0));
        player1.addInvocation(Compendium.invocations.get(1));
        player2.addInvocation(Compendium.invocations.get(2));
        player2.addInvocation(Compendium.invocations.get(3));
        
        // Creating views
        playerSecond = new PlayerInvocView(player2);
        playerMain = new MainPlayerInvocView(player1, playerSecond);
        
        energyMain = new MainEnergyView(player1, playerMain);
        
        playerSecond.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
        energySecond = new SecondaryEnergyView(player2);
        energySecond.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
        energySecond.setAlignment(Pos.BOTTOM_CENTER);

        this.setBottom(playerMain);
        this.setLeft(energyMain);
        this.setTop(playerSecond);
        this.setRight(energySecond);
    }
}
