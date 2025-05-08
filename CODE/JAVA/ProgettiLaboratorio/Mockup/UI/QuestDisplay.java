package UI;

import javafx.scene.layout.*;
import Quests.Compendium;

public class QuestDisplay extends HBox{
    public QuestList mains;
    public QuestList side;
    public QuestList contract;
    public QuestList dlc;

    public QuestDisplay(Compendium compendium) {
        mains = new QuestList("Main", compendium.getMainQuests());
        side = new QuestList("Side", compendium.getSideQuests());
        contract = new QuestList("Contract", compendium.getContractQuests());
        dlc = new QuestList("DLC", compendium.getDlcQuests());

        getChildren().addAll(mains, side, contract, dlc);
    }
}