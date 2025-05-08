package Quests;

import javafx.geometry.Insets;
import javafx.scene.control.Alert;
import javafx.scene.layout.*;
import javafx.scene.text.Text;

import UI.StatBar;


public class Main_Quest extends Quest {
    private Quest prevQuest;
    private String location;

    public Main_Quest(Quest prevQuest, String name, int level, String location, StatBar statBar) {
        super(name, level, 10, QuestType.MAIN, statBar);
        this.prevQuest = prevQuest;
        this.location = location;

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
        container.getChildren().add(new Text("Location: " + location));
        container.getChildren().add(new Text("Req: " +(prevQuest != null ? prevQuest.getName() : "None")));
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
        
        if (prevQuest != null && !prevQuest.isCompleted()) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Cannot Complete Quest");
            alert.setContentText("You need to complete the previous quest: " + prevQuest.getName() + " before you can complete this quest.");
            alert.show();
            
            return false;
        }

        return true;
    }
}
