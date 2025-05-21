package src.view.containers;

import java.util.Arrays;
import java.util.LinkedList;

import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.VBox;

import src.models.Fan;
import src.models.UserData;
import src.models.alimentation.Batteria_Alim;
import src.models.alimentation.Meccanico_Alim;
import src.models.alimentation.Presa_Alim;
import src.models.types.Parete_Type;
import src.models.types.Piantana_Type;
import src.models.types.Soffitto_Type;
import src.view.elements.Fan_View;

public class FanList extends VBox {
    private LinkedList<Fan> fanList = new LinkedList<Fan>(
            Arrays.asList(
                    new Fan("Ariete", new Batteria_Alim(), new Piantana_Type()),
                    new Fan("Bosch", new Presa_Alim(), new Parete_Type()),
                    new Fan("Bosch", new Meccanico_Alim(), new Parete_Type()),
                    new Fan("Bosch", new Batteria_Alim(), new Soffitto_Type()),
                    new Fan("Parkside", new Presa_Alim(), new Soffitto_Type())));

    private UserData user_data;
    private DataBar data_bar;

    public FanList(UserData user_data, DataBar data_bar) {
        this.user_data = user_data;
        this.data_bar = data_bar;
        updateFanList();
    }

    public void updateFanList() {
        this.getChildren().clear();
        for (Fan fan : fanList) {
            boolean isSubbed = false;
            boolean isPayable = false;

            if (user_data.getFans().contains(fan))
                isSubbed = true;
            if (user_data.getMoney() >= fan.getCosto())
                isPayable = true;

            Fan_View view = new Fan_View(fan, isPayable, isSubbed);
            view.setOnMouseClicked(new FanSubber());

            this.getChildren().add(view);
        }
    }

    public LinkedList<Fan> getFanList() {
        return fanList;
    }

    class FanSubber implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent event) {

            System.out.println("click");
            Fan_View view = (Fan_View) event.getSource();
            Fan fan = view.getFan();

            user_data.addFan(fan);
            data_bar.updateDataBar();
            updateFanList();
        }
    }
}
