package src.view.containers;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;

import javafx.scene.layout.VBox;
import src.models.UserData;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Alert.AlertType;

public class FunctionButtons extends VBox {
    UserData user_data;
    DataBar data_bar;
    FanList fan_list;

    public FunctionButtons( UserData user_data, DataBar data_bar, FanList fan_list) {
        this.user_data = user_data;
        this.data_bar = data_bar;
        this.fan_list = fan_list;

        Button add_funds= new Button("+100 Fondi");
        add_funds.setOnAction(new AddFunds());

        Button next_month = new Button("Prox. Mese");
        next_month.setOnAction(new NextMonth());

        this.getChildren().addAll(add_funds,next_month);
    }

    private class AddFunds implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            user_data.updateMoney(100);
            data_bar.updateDataBar();
            fan_list.updateFanList();
        }
    }

    private class NextMonth implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            user_data.incrementMonth();

            //CODE
            if (user_data.getMoney()>=user_data.getMonthly_cost()) {
                user_data.updateMoney(-user_data.getMonthly_cost());
            }else{
                Alert alert = new Alert(AlertType.ERROR);
                alert.setContentText("Sei Povero, rimosso fan piu' costoso");
                alert.showAndWait();

                user_data.removeCostlyFan();

                user_data.setMoney(0);
            }

            data_bar.updateDataBar();
            fan_list.updateFanList();
        }
    }
}
