package views.containers;

import javafx.scene.layout.VBox;
import views.elements.PointField;
import views.elements.WordField;

public class MainContainer extends VBox {
    GridContainer grid = new GridContainer();
    InfoContainer info = new InfoContainer();

    public MainContainer(){
        super();
        WordField word = new WordField();
        PointField points = new PointField();

        GridContainer.ClickHandler.wordField = word;
        GridContainer.ClickHandler.pointField = points;
        PointField.EndGame.word = word;

    }
}
