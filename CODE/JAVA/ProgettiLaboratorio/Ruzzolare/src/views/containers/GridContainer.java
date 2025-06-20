package views.containers;

import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import models.elements.Cell;
import models.util.Bonus;
import views.elements.CellView;
import models.util.Letters;
import views.elements.PointField;
import views.elements.View;
import views.elements.WordField;

import java.util.Random;

public class GridContainer extends GridPane implements View {
    private final int HEIGHT = 280;
    private final int WIDTH = 280;
    private final int ROWL = 4;
    private final int COLL = 4;
    private CellView[][] cells;

    public GridContainer(){
        super();
        setPrefSize(WIDTH,HEIGHT);
        updateView();
    }

    public void updateView(){
        Random rand = new Random();
        for (int i = 0; i < ROWL; i++) {
            cells[i]=new CellView[COLL];
            for (int j = 0; j < COLL; j++) {
                Bonus b = null;
                if ((i ==0 && j==0) || (i==ROWL-1&&j==COLL-1)){
                    b = Bonus.V2;
                } else if ((i ==0 && j==COLL-1) || (i==ROWL-1&&j==0)) {
                    b = Bonus.V3;
                }
                cells[i][j] = new CellView(new Cell(Letters.values()[rand.nextInt(4)], b));
                cells[i][j].setOnMouseClicked(new ClickHandler());
                this.add(cells[i][j],i,j);
            }
        }
    }

    static class ClickHandler implements EventHandler<MouseEvent>{
        static WordField wordField;
        static PointField pointField;
        @Override
        public void handle(MouseEvent event) {
            CellView cellV = (CellView) event.getSource();
            Cell cell = cellV.getCell();

            if (cellV.getActive()){
                return;
            }

            wordField.concatWord(cell.getLetterS());
            pointField.addPoints(cell.getLetter().getPoints()*cell.getBonus().getMult());
        }
    }
}
