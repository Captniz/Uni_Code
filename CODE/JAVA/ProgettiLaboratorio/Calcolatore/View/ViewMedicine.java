package View;

import Medicine.AbsMedicine;
import Medicine.RecMedicine;
import javafx.geometry.Insets;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;

public class ViewMedicine extends VBox{

    private Label name;
    private Label cost;
    private Label spoilDate;
    private Label type;

    private AbsMedicine med; 

    public ViewMedicine(AbsMedicine medicine) {
        med = medicine;

        this.name = new Label(medicine.getName());
        this.spoilDate = new Label(medicine.isSpoiled() ? "Scaduto" : medicine.getSpoil().toString());
        
        if (medicine.getType() == AbsMedicine.Type.BANCO){
            this.cost = new Label("Costo : " + medicine.getCost() + "€");
            this.type = new Label("Medicinale da Banco");    
        }else{
            this.cost = new Label("Costo base : "+ ((RecMedicine) medicine).getStandardCost() + "€ , Scontato a : " + medicine.getCost() + "€");
            this.type = new Label("Medicinale con Ricetta : " + (((RecMedicine) medicine).getUses() == 1 ? "Non ripetibile" : ((RecMedicine) medicine).getUses()));
        }

        this.getChildren().addAll(this.name, this.cost, this.spoilDate, this.type);
        this.setPadding(new Insets(10));
    }

    public AbsMedicine getMedicine() {
        return med;
    }
}
