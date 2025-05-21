package src.view.elements;

import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import src.models.Fan;

public class Fan_View extends HBox {
    private Fan fan;
    private boolean isPayable;
    private boolean isSubbed;

    public Fan_View(Fan fan, boolean isPayable, boolean isSubbed) {
        this.fan = fan;
        this.isPayable = isPayable;
        this.isSubbed = isSubbed;
        updateView();
    }

    public void updateView() {
        this.getChildren().clear();

        Color circle_infil = isSubbed ? Color.RED : Color.BLUE;
        Color circle_stroke = isPayable ? Color.BLACK : Color.GRAY;

        //ImageView im = new ImageView(new Image("src/view/images/fan.png"));
        Circle icon = new Circle(40, circle_infil);
        icon.setStroke(circle_stroke);
        icon.setStrokeWidth(3);

        VBox info = new VBox();

        Label marca = new Label(fan.getMarca());
        Label specs = new Label(
                "Tipo : " + fan.getTipo().getTypeStr() + " Alimentazione : " + fan.getAlimentazione().getAlimStr());
        Label costo = new Label("Costo : " + fan.getCosto());

        info.getChildren().addAll(marca, specs, costo);

        this.getChildren().addAll(icon, info);
    }

    public void setPayable(boolean val) {
        isPayable = val;
        updateView();
    }

    public void setSubbed(boolean val) {
        isSubbed = val;
        updateView();
    }

    public Fan getFan() {
        return fan;
    }
}
