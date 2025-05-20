package src.views;

import javafx.geometry.Insets;
import javafx.scene.layout.VBox;
import src.Player;
import src.Energy;
import javafx.scene.Node;

public abstract class AbsListEnergyView extends VBox{

    Player player;

    public AbsListEnergyView(Player player) {
        super();
        this.player = player;
        updateVisuals();
    }

    private void updateVisuals() {
        this.getChildren().clear();
        for (Energy energy : player.getEnergies()) {
            SingleEnergyView viewEner = new SingleEnergyView(energy, player.getEnergies().indexOf(energy));
            VBox.setMargin(viewEner, new Insets(0, 0, 10, 0));
            this.getChildren().add(viewEner);
        }
    }

    abstract public void appendHandlers(Node node);

    public void updateEnergy(Player player) {
        this.player = player;
        this.updateVisuals();
    }

    public void updateEnergy() {
        this.updateVisuals();
        for (Node node : this.getChildren()) {
            appendHandlers(node);
        }
    }
}
