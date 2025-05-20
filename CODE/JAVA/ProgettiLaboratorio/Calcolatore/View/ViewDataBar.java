package View;

import javafx.scene.layout.HBox;
import javafx.scene.control.Label;
import java.util.Date;

public class ViewDataBar extends HBox {
    public ViewDataBar() {
        super();
        this.getChildren().add(new Label("Money: " + 0 + "€\t"));
        this.getChildren().add(new Label("Date: " + new Date()));    
    }

    public ViewDataBar(int money, Date date) {
        super();
        this.getChildren().add(new Label("Money: " + money + "€\t"));
        this.getChildren().add(new Label("Date: " + date));
    }


    public void updateBar(int money, Date date) {
        this.getChildren().clear();
        this.getChildren().add(new Label("Money: " + money + "€\t"));
        this.getChildren().add(new Label("Date: " + date));
    }
}
