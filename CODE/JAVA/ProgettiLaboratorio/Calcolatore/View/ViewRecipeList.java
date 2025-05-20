package View;
import java.util.LinkedList;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.layout.VBox;

import Recipe.Recipe;

public class ViewRecipeList extends VBox {
    public ViewRecipeList(LinkedList<ViewRecipe> recipes, ViewMedicineDetail medicineDetail) {
        for (ViewRecipe recipe : recipes) {
            this.getChildren().add(recipe);
        }

        this.addEventHandler(ActionEvent.ACTION, new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                for (ViewRecipe recipe : recipes) {
                    recipe.resetSelection();
                    if (!recipe.getRecipe().isExpired()){
                        recipe.disableProperty().set(false);
                    }
                }

                if (event.getTarget() instanceof ViewRecipe) {
                    ((ViewRecipe) event.getTarget()).setSelection("Ricetta selezionata");
                    medicineDetail.setRecipe((ViewRecipe) event.getTarget());
                    ((ViewRecipe) event.getTarget()).disableProperty().set(true);
                }
            }
        });
    }

    public LinkedList<Recipe> getRecipes() {
        LinkedList<Recipe> recipes = new LinkedList<Recipe>();
        for (int i = 0; i < this.getChildren().size(); i++) {
            recipes.add(((ViewRecipe) this.getChildren().get(i)).getRecipe());
        }
        return recipes;
    }
}