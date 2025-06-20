package views.elements;

import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import models.elements.Score;
import models.elements.ScoreComparator;

import java.util.ArrayList;
import java.util.HashMap;

public class Ranking extends VBox implements View{
    private ArrayList<Score> ranks;

    public Ranking(){
        super();
        ranks = new ArrayList<Score>();
        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().clear();
        for(Score rank : ranks){
            this.getChildren().add(new Text(rank.name + ":" + rank.points));
        }
    }

    public void addRank(String name, int points){
        ranks.add(new Score(name,points));
        ranks.sort(new ScoreComparator());
        updateView();
    }
}