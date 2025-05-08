package Quests;

import javafx.geometry.Insets;
import javafx.scene.control.Alert;
import javafx.scene.layout.*;
import javafx.scene.text.Text;

import UI.StatBar;


public class Side_Quest extends Quest {
    private String NPCName;

    public Side_Quest(String name, int level, int reward, String NPCName, StatBar statBar) {
        super(name, level, reward, QuestType.SIDE, statBar);
        this.NPCName = NPCName;
        questLevelReward = 2;

        VBox container = buildQuestInfo(questName, questLevel, questReward);    
        container.setPadding(new Insets(VSPACE));    
        container.getChildren().add(completeButton);
        getChildren().addAll(background, container);
    }

    @Override
    public VBox buildQuestInfo(String questName, int questLevel, int questReward) {
        VBox container = new VBox();
        container.getChildren().add(new Text(questName + " ("+questReward+")"));
        container.getChildren().add(new Text("Min Level: " + questLevel));
        container.getChildren().add(new Text("NPC: " + NPCName));
        return container;
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
