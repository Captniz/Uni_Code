package com.company.src.views.containers;

import com.company.src.models.elements.brotypes.AbsBro;
import com.company.src.views.View;
import com.company.src.views.elements.BigBroView;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

import javax.swing.*;

public class GraphPanel extends StackPane implements View {
    private final int WIDTH = 300;
    private final int HEIGHT = 300;

    AbsBro bro;
    EnemyBar enemy;

    public GraphPanel(EnemyBar enemy) {
        super();
        setPrefSize(WIDTH, HEIGHT);
        bro=null;
        this.enemy = enemy;
        backgroundProperty().set(new Background(new BackgroundFill(Color.BLACK, null, null)));
    }

    @Override
    public void updateView() {
        this.getChildren().clear();
        Circle circle = new Circle((double)bro.getAttack().getType().getRange(),Color.GREEN);
        BigBroView bigBroView = new BigBroView(bro);
        circle.setOnMouseClicked(new DamageEvent());
        StackPane.setAlignment(bigBroView, Pos.CENTER);
        this.getChildren().add(circle);
        this.getChildren().add(bigBroView);
    }

    public void setBro(AbsBro bro) {
        this.bro = bro;
        updateView();
    }

    class DamageEvent implements EventHandler<MouseEvent>{
        @Override
        public void handle(MouseEvent event) {
            try{
                enemy.updateLife(-bro.getAttack().getDamage());
            }catch (EnemyBar.EnemyKilled e){
                e.printStackTrace();
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Killed");
                alert.setContentText("Hai ucciso il nemico");
                alert.showAndWait();
                enemy.setLife(enemy.getMaxEnemyLife());
            }
        }
    }
}
