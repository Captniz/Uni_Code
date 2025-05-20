package src.views;

import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.scene.layout.Border;
import javafx.scene.layout.BorderStroke;
import javafx.scene.layout.BorderStrokeStyle;
import javafx.scene.layout.BorderWidths;
import javafx.scene.layout.StackPane;
import javafx.scene.control.Label;
import src.Energy;
import src.Invocation;

public class InvocationView extends StackPane {
    Invocation invocation;
    VBox data;
    Label invocationName;
    Label PV;
    Label assignedEnergy;
    Label attackNameAndCost;
    Label attackDamage;

    public InvocationView(Invocation invocation) {
        super();
        this.invocation = invocation;
        this.setPrefSize(120, 120);
        this.setBackground(Energy.getCorrespondingBg(invocation.getType()));
        if (invocation.getInvocationType() == Invocation.InvocationType.SUPREME) {
            this.setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID, null, new BorderWidths(3))));
        }

        this.invocationName = new Label(invocation.getName());
        this.PV = new Label("PV: " + invocation.getPV() + "/" + invocation.getMaxPV());
        this.assignedEnergy = new Label("Energy: " + invocation.getAssignedEnergy());
        this.attackNameAndCost = new Label(invocation.getAttack().getName() + " ( " + invocation.getAttack().getEnergyCost() + " )");
        this.attackDamage = new Label("Damage: " + invocation.getAttack().getDamage());

        data = new VBox();
        data.setPadding(new Insets(3));
        data.getChildren().addAll(invocationName, PV, assignedEnergy, attackNameAndCost, attackDamage);

        this.getChildren().add(data);
    }

    public void updateInvocation(Invocation invocation) {
        this.invocation = invocation;
        this.invocationName.setText(invocation.getName());
        this.PV.setText("PV: " + invocation.getPV() + "/" + invocation.getMaxPV());
        this.assignedEnergy.setText("Energy: " + invocation.getAssignedEnergy());
        this.attackNameAndCost.setText(invocation.getAttack().getName() + " ( " + invocation.getAttack().getEnergyCost() + " )");
        this.attackDamage.setText("Damage: " + invocation.getAttack().getDamage());
    }

    public void updateInvocation() {
        this.invocationName.setText(invocation.getName());
        this.PV.setText("PV: " + invocation.getPV() + "/" + invocation.getMaxPV());
        this.assignedEnergy.setText("Energy: " + invocation.getAssignedEnergy());
        this.attackNameAndCost.setText(invocation.getAttack().getName() + " ( " + invocation.getAttack().getEnergyCost() + " )");
        this.attackDamage.setText("Damage: " + invocation.getAttack().getDamage());
    }

    public Invocation getInvocation() {
        return invocation;
    }
}
