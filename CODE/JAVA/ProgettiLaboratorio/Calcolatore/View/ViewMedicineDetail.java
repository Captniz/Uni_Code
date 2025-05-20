package View;

import Medicine.AbsMedicine;

import java.util.LinkedList;

import Controller.ControllerDataBar;
import javafx.scene.layout.VBox;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;

public class ViewMedicineDetail extends VBox {
    AbsMedicine selectedMed;
    ViewRecipe selectedRec;
    Button buyButton;
    ControllerDataBar dataBar;
    LinkedList<ViewRecipe> recipeList;

    public ViewMedicineDetail(ControllerDataBar data, LinkedList<ViewRecipe> recipeList) {
        super();
        buyButton = new Button("Buy");
        buyButton.setOnAction(new CheckBuy());
        this.dataBar = data;
        this.recipeList = recipeList;
        selectedMed = null;
        selectedRec = null;
    }

    public void setMedicine(ViewMedicine medicine) {
        selectedMed = medicine.getMedicine();
        this.getChildren().clear();
        this.getChildren().add(medicine);
        this.getChildren().add(buyButton);
    }    

    public void setRecipe(ViewRecipe recipe) {
        selectedRec = recipe;
    }

    class CheckBuy implements EventHandler<ActionEvent> {
        @Override
        public void handle(javafx.event.ActionEvent event) {

            if (dataBar.getMoney() < selectedMed.getCost()) {

                System.out.println(dataBar.getMoney());
                System.out.println(selectedMed.getCost());

                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error");
                alert.setContentText("You don't have enough money");
                alert.showAndWait();
                return;
            } 
            if (selectedMed.isSpoiled()) {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error");
                alert.setContentText("This medicine is expired");
                alert.showAndWait();
                return;
            }
            if (selectedMed.getType() == AbsMedicine.Type.RICETTA) {
                if (selectedRec == null ||!(selectedMed.getName().equals(selectedRec.getRecipe().getMedicineName()))) {
                    boolean alreadyInRecipe = false;
                    for (ViewRecipe recipe : recipeList) {
                        if (recipe.getRecipe().getMedicineName().equals(selectedMed.getName())) {
                            alreadyInRecipe = true;
                            break;
                        }
                    }
                    if (alreadyInRecipe) {
                        Alert alert = new Alert(Alert.AlertType.ERROR);
                        alert.setTitle("Error");
                        alert.setContentText("This medicine is already in your recipes but its not selected");
                        alert.showAndWait();
                        return;
                    } else {
                        Alert alert = new Alert(Alert.AlertType.ERROR);
                        alert.setTitle("Error");
                        alert.setContentText("This medicine is not in your recipes");
                        alert.showAndWait();
                        return;
                    }
                }
                if (selectedRec.getRecipe().use()) {
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error");
                    alert.setContentText("You have already bought all the medicine");
                    alert.showAndWait();
                    return;
                }
            }

            //buy the medicine
            dataBar.updateBar(-selectedMed.getCost());
            if (selectedRec != null) {
                selectedRec.resetSelection();
            }
        }
    }
}
