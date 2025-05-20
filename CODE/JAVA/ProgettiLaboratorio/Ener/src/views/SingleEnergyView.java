package src.views;

import javafx.scene.layout.StackPane;
import src.Energy;

public class SingleEnergyView extends StackPane {
    private int index;
    public SingleEnergyView(Energy energy, int index) {
        this.setPrefSize(70, 30);
        this.setBackground(energy.getCorrespondingBg());
        this.index = index;
    }

    public int getIndex() {
        return index;
    }

}
