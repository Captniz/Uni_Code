package Medicine;

import java.util.Date;

public abstract class AbsMedicine {
    public static enum Type {
        BANCO,
        RICETTA
    }
    
    String name;
    int cost;
    Date spoil;
    Type type;
    boolean spoiled;

    AbsMedicine(String name, int cost, Date spoil, Type type) {
        this.name = name;
        this.cost = cost;
        this.spoil = spoil;
        this.type = type;
        if (spoil.before(new Date())) {
            this.spoiled = true;
        } else {
            this.spoiled = false;
        }
    }

    AbsMedicine() {
        this.name = "";
        this.cost = 0;
        this.spoil = new Date();
        this.spoiled = false;
    }

    public String getName() {
        return name;
    }

    public int getCost() {
        return cost;
    }

    public Date getSpoil() {
        return spoil;
    }

    public Type getType() {
        return type;
    }

    public boolean isSpoiled() {
        return spoiled;
    }
    
    public void spoil() {
        this.spoiled = true;
    }

}
