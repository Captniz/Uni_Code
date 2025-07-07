package com.company.src.views.containers;

import com.company.src.views.View;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;

public class EnemyBar extends HBox implements View {
    private int enemyLife;
    private final int maxEnemyLife;

    public EnemyBar(){
        super();
        this.maxEnemyLife= 10000;
        this.enemyLife = maxEnemyLife;
        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().clear();
        this.getChildren().add(new Label("HP : " + enemyLife));
        this.getChildren().add(new ResetButton());
    }

    public void updateLife(int lifemod) throws EnemyKilled{
        enemyLife += lifemod;
        if (enemyLife<=0){
            throw new EnemyKilled();
        }
        updateView();
    }

    public void setLife(int life){
        this.enemyLife = life;
        updateView();
    }

    public int getMaxEnemyLife() {
        return maxEnemyLife;
    }

    private class ResetButton extends Button {
        public ResetButton(){
            super("Reset");
            this.setOnMouseClicked(event -> {
                setLife(maxEnemyLife);
            });
        }
    }

    public class EnemyKilled extends Exception {}
}
