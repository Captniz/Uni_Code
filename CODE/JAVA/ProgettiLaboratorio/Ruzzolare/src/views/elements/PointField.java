package views.elements;

import javafx.event.EventHandler;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextInputDialog;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import views.containers.GridContainer;

import java.util.Optional;

public class PointField extends HBox implements View{
    private Button end;
    private int points;

    public PointField(){
        super();
        points = 0;
        end = new Button("End");
        end.setOnMouseClicked(new EndGame(this));
        this.getChildren().addAll(end, new Text());
        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().remove(this.getChildren().getLast());
        this.getChildren().add(new Text("Punteggio : "+points));
    }

    public void setPoints(int points) {
        this.points = points;
        updateView();
    }

    public int getPoints() {
        return points;
    }

    public void addPoints(int points){
        this.points+=points;
        updateView();
    }

    public void clearPoints(){
        this.points=0;
        updateView();
    }

    public static class EndGame implements EventHandler<MouseEvent> {
        private static Ranking ranks;
        public static WordField word;
        public static GridContainer grid;
        private PointField points;

        EndGame(PointField p){
            points = p;
        }

        @Override
        public void handle(MouseEvent event){
            TextInputDialog dialog = new TextInputDialog("name");
            dialog.setTitle("Input Dialog");
            dialog.setHeaderText("Enter your name");
            dialog.setContentText("Name:");

            Optional<String> name = dialog.showAndWait();
            if (name.isPresent()){
                ranks.addRank(name.get(),points.getPoints());
                word.clearWord();
                points.clearPoints();
                grid.updateView();
            }else {
                Alert a = new Alert(Alert.AlertType.ERROR);
                a.setContentText("non hai messo il nome pirla");
                a.showAndWait();
                handle(event);
            }
        }
    }
}