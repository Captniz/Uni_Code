package src.views;

import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import javafx.event.EventHandler;
import src.Player;

public class SecondaryEnergyView extends AbsListEnergyView{
    public SecondaryEnergyView(Player player) {
        super(player);
        for (Node node : this.getChildren()) {
            node.setOnMouseClicked(new MouseEventHandler());
        }
    }

    @Override
    public void appendHandlers(Node node) {
        node.setOnMouseClicked(new MouseEventHandler());
    }

    class MouseEventHandler implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent event) {
            
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setContentText("Opponent's energy cannot be used");
            alert.showAndWait();
            return;
        }
    }
}
