package src.view.containers;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;

import javafx.scene.layout.VBox;
import src.models.CostComparator;
import src.models.TypeComparator;
import javafx.scene.control.Button;

public class OrderingButtons extends VBox {
    FanList fan_list;

    public OrderingButtons(FanList fanList) {
        this.fan_list = fanList;

        Button type_order = new Button("Ordina per Tipo");
        type_order.setOnAction(new TypeOrdering());

        Button cost_order = new Button("Ordina per Costo");
        cost_order.setOnAction(new CostOrdering());

        this.getChildren().addAll(type_order,cost_order);
    }

    private class TypeOrdering implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            fan_list.getFanList().sort(new TypeComparator());
            fan_list.updateFanList();
        }
    }

    private class CostOrdering implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            fan_list.getFanList().sort(new CostComparator());
            fan_list.updateFanList();
        }
    }
}
