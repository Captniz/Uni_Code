package Lecture_14.EsempioCalc;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;

class OperationButton extends Button implements EventHandler<ActionEvent> {
    MiniCalculator2 mc = null;

    public OperationButton(MiniCalculator2 mc, String label, String id) {
        super(label);
        this.mc = mc;
        setId(id);
        addEventFilter(ActionEvent.ACTION, this);
    }

    void setOBwidth(double w) {
        this.setMaxWidth(w);
        this.setMinWidth(w);
    }

    @Override
    public void handle(ActionEvent t) {
        mc.compute(this.getId());
    }
}