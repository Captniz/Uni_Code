package src.views;

import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import javafx.event.EventHandler;
import src.Player;
import src.Energy.EnergyType;

import src.Invocation;

public class MainEnergyView extends AbsListEnergyView{
    PlayerInvocView mInvocationView;

    public MainEnergyView(Player player, PlayerInvocView mInvocationView) {
        super(player);
        for (Node node : this.getChildren()) {
            node.setOnMouseClicked(new MouseEventHandler(this,mInvocationView));
        }

        this.mInvocationView = mInvocationView;
    }

    @Override
    public void appendHandlers(Node node) {
        node.setOnMouseClicked(new MouseEventHandler(this, mInvocationView));
    }

    class MouseEventHandler implements EventHandler<MouseEvent> {
        //onclick

        MainEnergyView thisView;
        PlayerInvocView mInvocationView;

        MouseEventHandler(MainEnergyView view, PlayerInvocView mInvocationView) {
            this.thisView = view;
            this.mInvocationView = mInvocationView;
        }

        @Override
        public void handle(MouseEvent event) {
            int energyIndex = ((SingleEnergyView) event.getTarget()).getIndex();       
            
            EnergyType energyType = player.getEnergies().get(energyIndex).getType();
            
            Invocation firstInvoc = player.getInvocations().get(0);
            if ( energyType == EnergyType.NEUTRAL || energyType == firstInvoc.getType() ){
                //Add energy to invocation
                firstInvoc.setAssignedEnergy(firstInvoc.getAssignedEnergy() + 1);

                //Remove energy from player
                player.getEnergies().remove(energyIndex);
                
                // Update invoc view
                mInvocationView.updateInvocations();

                //Update visuals
                thisView.updateEnergy();
            }else{
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error");
                alert.setContentText("Wrong energy type selected");
                alert.showAndWait();
                return;
            }
        }
    }
}
