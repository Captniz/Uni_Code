package views.containers;


import javafx.scene.layout.VBox;
import views.elements.PointField;
import views.elements.Ranking;
import views.elements.View;
import views.elements.WordField;


public class InfoContainer extends VBox implements View {
    Ranking ranks;
    WordField wordField;
    PointField pointField;

    public InfoContainer(){
        super();
        ranks = new Ranking();
        wordField = new WordField();
        pointField = new PointField();
        updateView();
    }

    public InfoContainer(Ranking r, WordField w, PointField p){
        super();
        ranks = r;
        wordField = w;
        pointField = p;
        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().clear();
        ranks.updateView();
        wordField.updateView();
        pointField.updateView();
    }
}
