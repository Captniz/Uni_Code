package views.elements;

import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import models.elements.Cell;

public class CellView extends StackPane implements View{
    HBox text;
    Cell cell;
    boolean active;

    public CellView(Cell cell){
        this.cell = cell;
        this.active = false;
        updateView();
    }

    public void updateView(){
        backgroundProperty().set(new Background(new BackgroundFill(Color.GREY,null,null)));
        text = new HBox(new Text(cell.getLetterS()+(cell.getBonus()==null?"":("*"+cell.getBonusS()))));
    }

    public boolean toggleActive(){
        active = !active;

        if (active){
            backgroundProperty().set(new Background(new BackgroundFill(Color.ORANGE,null,null)));
        }else{
            backgroundProperty().set(new Background(new BackgroundFill(Color.GREY,null,null)));
        }

        return active;
    }

    public Cell getCell() {
        return cell;
    }

    public boolean getActive(){
        return active;
    }
}
