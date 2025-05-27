package src.views.element;

import javafx.scene.control.Label;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderStroke;
import javafx.scene.layout.BorderStrokeStyle;
import javafx.scene.layout.BorderWidths;
import javafx.scene.layout.Border;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import src.models.element.mutations.Abs_Mutation;

public class Mutation_View extends StackPane {
    private Abs_Mutation mut;
    private boolean isActive;

    private final int WIDTH = 70;
    private final int HEIGHT = 70;

    public Mutation_View(Abs_Mutation mut) {
        this.mut = mut;
        this.isActive = false;
        this.setPrefHeight(HEIGHT);
        this.setPrefWidth(WIDTH);

        updateView();
    }

    public Mutation_View(Abs_Mutation mut, boolean val) {
        this.mut = mut;
        this.isActive = val;
        this.setPrefHeight(HEIGHT);
        this.setPrefWidth(WIDTH);

        updateView();
    }

    public void updateView() {
        this.getChildren().clear();

        this.setBackground(new Background(new BackgroundFill(mut.getType().getBgColor(), null, null)));

        this.setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID, null, new BorderWidths(2))));

        this.getChildren().add(new Label((isActive ? "- " : "+ ") + mut.getName()));
    }

    public void setIsActive(boolean val) {
        isActive = val;
    }

    public boolean getIsActive() {
        return isActive;
    }

    public void toggleActive() {
        isActive = !isActive;
    }

    public Abs_Mutation getMutation() {
        return mut;
    }
}
