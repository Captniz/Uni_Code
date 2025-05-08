package UI;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.text.*;
import java.util.List;

import Quests.Quest;
import Quests.QuestComparatorByName;
import Quests.QuestComparatorByReward;

public class QuestList extends VBox {
    QuestList(String title, List<? extends Quest> quests) {
        Text titleText = new Text(title+"\n");

        
        VBox questBox = new VBox();
        for (Quest quest : quests) {
            questBox.getChildren().add(quest);
        }

        Button sort1 = new Button("Sort Alphabetically");
        Button sort2 = new Button("Sort by Reward");

        sort1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                quests.sort(new QuestComparatorByName());
                questBox.getChildren().clear();
                questBox.getChildren().add(titleText);
                for (Quest quest : quests) {
                    questBox.getChildren().add(quest);
                }
            }
        });

        sort2.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                quests.sort(new QuestComparatorByReward());
                questBox.getChildren().clear();
                questBox.getChildren().add(titleText);
                for (Quest quest : quests) {
                    questBox.getChildren().add(quest);
                }
            }
        });

        getChildren().addAll(titleText, questBox, sort1, sort2);
    }

    public void setQuests(Quest quests[]) {
        getChildren().clear();
        for (Quest quest : quests) {
            getChildren().add(quest);
        }
    }
}