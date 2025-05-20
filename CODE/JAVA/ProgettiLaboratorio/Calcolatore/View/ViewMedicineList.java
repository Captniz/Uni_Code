package View;

import java.util.LinkedList;

import javafx.event.EventHandler;
import javafx.scene.layout.VBox;
import javafx.scene.input.MouseEvent;

public class ViewMedicineList extends VBox {
    
    public ViewMedicineList() {
        super();
    }

    public ViewMedicineList(LinkedList<ViewMedicine> medicines, ViewMedicineDetail medicineDetail) {
        super();
        for (ViewMedicine medicine : medicines) {
            this.getChildren().add(medicine);
        }

        this.onMouseClickedProperty().set(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                if (event.getTarget() instanceof ViewMedicine) {
                    ViewMedicine selectedMedicine = new ViewMedicine(((ViewMedicine) event.getTarget()).getMedicine());
                    medicineDetail.setMedicine(selectedMedicine);
                }
            }
        });
    }
}
