package com.company.src.views.containers;

import com.company.src.models.elements.brotypes.AbsBro;
import com.company.src.models.utility.Compendium;
import com.company.src.views.View;
import com.company.src.views.elements.BroView;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class BroList extends HBox implements View {
    ArrayList<AbsBro> bros;
    GraphPanel graphPanel;

    BroList(GraphPanel graphPanel) {
        super();
        this.graphPanel = graphPanel;
        this.bros = new ArrayList<>();
        bros.addAll(Compendium.compendium);
        Collections.sort(bros);
        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().clear();
        for (AbsBro bro : bros) {
            BroView broView = new BroView(bro);
            HBox.setMargin(broView,new Insets(0,BroView.MARGIN,0,BroView.MARGIN));
            broView.setOnMouseClicked(new OnClickBro());
            this.getChildren().add(broView);
        }
    }

    public void sort(Comparator<AbsBro> comparator) {
        bros.sort(comparator);
        updateView();
    }

    private class OnClickBro implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent event) {
            AbsBro bro = ((BroView)event.getSource()).getBro();
            graphPanel.setBro(bro);
        }
    }
}
