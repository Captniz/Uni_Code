package Quests;

import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.*;
import javafx.scene.control.*;
import UI.StatBar;
import javafx.event.*;
import javafx.geometry.Insets;



public abstract class Quest extends StackPane implements Comparable<Quest> {
    final int WIDTH = 400;
    final int HEIGHT = 150;
    final int VSPACE = 5;
    protected Rectangle background;
    protected Button completeButton;

    protected StatBar statBar;
    
    enum QuestType {
        MAIN,
        SIDE,
        CONTRACT,
        TREASURE,
        DLC
    }

    protected String questName;
    protected boolean isCompleted;
    protected int questLevel;
    protected int questReward;
    protected int questLevelReward;

    protected QuestType questType;

    Quest(String name, int level, int reward, QuestType type, StatBar statBar) {
        setWidth(WIDTH);
        setHeight(HEIGHT);
        setPadding(new Insets(VSPACE));
        

        this.questName = name;
        this.questLevel = level;
        this.isCompleted = false;
        this.questReward = reward;
        this.questType = type;
        this.statBar = statBar;
        questLevelReward = 1;

        background = new Rectangle(WIDTH, HEIGHT);
        background.setFill(Color.BEIGE);
        background.setStroke(Color.BLACK);
        
        completeButton = new Button("Complete Quest");
        completeButton.setOnAction(new CompleteQuest(this));
    }

    public abstract VBox buildQuestInfo(String questName, int questLevel, int questReward);
    public abstract boolean checkQuestCompletion();
    
    public String getName() {
        return questName;
    }

    public int getReward() {
        return questReward;
    }

    public boolean isCompleted() {
        return isCompleted;
    }

    class CompleteQuest implements EventHandler<ActionEvent> {
        Quest quest;

        CompleteQuest(Quest quest) {
            this.quest = quest;
        }
        
        @Override
        public void handle(ActionEvent event) {
            if (checkQuestCompletion()) {
                quest.background.setFill(Color.LIGHTGREEN);
                quest.completeButton.setText("Quest Completed");
                quest.completeButton.setDisable(true);

                quest.isCompleted = true;

                statBar.setGP(statBar.getGP() + quest.questReward);

                statBar.setLVL(statBar.getLVL() + questLevelReward);
            }
        }
    }

    @Override
    public String toString () {
        String str = "Quest Name: " + questName + "\n";
        str += "Quest Type: " + questType + "\n";
        str += "Quest Level: " + questLevel + "\n";
        str += "Quest Reward: " + questReward + "\n";
        str += "Quest Level Reward: " + questLevelReward + "\n";
        str += "Quest Completed: " + isCompleted + "\n";

        return str;
    }

    @Override
    public int compareTo(Quest other) {
        return this.questName.compareTo(other.questName);
    }
}