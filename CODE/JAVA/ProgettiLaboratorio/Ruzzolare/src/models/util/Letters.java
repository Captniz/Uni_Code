package models.util;

public enum Letters {
    A(1),
    E(2),
    R(5);

    private final int points;

    private Letters(int point){
        this.points = point;
    }

    public int getPoints() {
        return points;
    }
}
