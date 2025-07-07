package com.company.src.models.utility;

import javafx.scene.paint.Color;

public enum RangeBros implements BroSubtype{
    SNIPER(Color.OLIVE,3000,5500),
    ARTILLERY(Color.CYAN,2000,3500);

    private final Color color;
    private final String speed = "media";
    private final int minLife;
    private final int maxLife;

    private RangeBros(Color color, int minLife, int maxLife){
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
