package Quests;

import javafx.geometry.Insets;
import javafx.scene.control.Alert;
import javafx.scene.layout.*;
import javafx.scene.text.Text;

import UI.StatBar;


public class Contract_Quest extends Quest {
    private String location;
    private String[] monsters;

    public Contract_Quest(String name, int level, int reward, String location, String[] monsters, StatBar statBar) {
        super(name, level, reward+(reward*20/100), QuestType.CONTRACT, statBar);
        this.location = location;
        this.monsters = monsters.clone();

        VBox container = buildQuestInfo(questName, questLevel, reward);      
        container.setPadding(new Insets(VSPACE));  
        container.getChildren().add(completeButton);
        getChildren().addAll(background, container);
    }

    @Override
    public VBox buildQuestInfo(String questName, int questLevel, int questReward) {
        VBox container = new VBox();
        container.getChildren().add(new Text(questName + " ("+questReward+")"));
        container.getChildren().add(new Text("Min Level: " + questLevel));
        container.getChildren().add(new Text("Monsters: " + arrayToString(monsters)));
        if (location != null) {
            container.getChildren().add(new Text("Location: " + location));
        }
        return container;
    }

    private String arrayToString(String[] array) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        return sb.toString();
    }

    @Override
    public boolean checkQuestCompletion() {
        
        if (questLevel > statBar.getLVL()) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Cannot Complete Quest");
            alert.setContentText("You need to be at least level " + questLevel + " to complete this quest.");
            alert.show();
        
            return false;
        }

        return true;
    }
}
