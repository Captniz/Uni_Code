package com.company.src.models.utility;

import javafx.scene.paint.Color;

public enum TankBros implements BroSubtype{
    TANK(Color.MAGENTA, 8000, 10500);


    private final Color color;
    private final String speed="lenta";
    private final int minLife;
    private final int maxLife;

    private TankBros(Color color, int minLife, int maxLife){
        this.color = color;
        this.minLife = minLife;
        this.maxLife = maxLife;
    }

    public int getMaxLife() {
        return maxLife;
    }

    public int getMinLife() {
        return minLife;
    }

    public String getSpeed() {
        return speed;
    }

    public Color getColor() {
        return color;
    }

}
