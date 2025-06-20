package models.util;

public enum Bonus {
    V2(2),
    V3(3);

    private final int mult;

    private Bonus(int mult){
        this.mult = mult;
    }

    public int getMult() {
        return mult;
    }
}
