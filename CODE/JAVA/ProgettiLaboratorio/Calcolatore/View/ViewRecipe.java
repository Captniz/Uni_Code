package View;

import Recipe.Recipe;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;

public class ViewRecipe extends Button{

    private Label name;
    private Label spoilDate;
    private Label selection;
    private VBox container; 

    private Recipe rec; 

    public ViewRecipe(Recipe recipe) {
        rec = recipe;

        container = new VBox();

        this.name = new Label("Ricetta per : "+ recipe.getMedicineName());
        this.spoilDate = new Label(recipe.isExpired() ? "Scaduto" : "Valida fino al : " + recipe.getExpirationDate().toString());

        if (recipe.isExpired()) {
            this.disableProperty().set(true);
        } 

        selection = new Label();

        container.getChildren().addAll(name, spoilDate, selection);
        this.setGraphic(container);
    }

    public Recipe getRecipe() {
        return rec;
    }

    public void resetSelection() {
        selection.setText("");
    }

    public void setSelection(String text) {
        selection.setText(text);
    }
}

