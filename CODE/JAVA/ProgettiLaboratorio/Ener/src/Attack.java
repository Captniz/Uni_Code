package src;

import src.Energy.EnergyType;

public class Attack {
    String name;
    EnergyType type;
    int energyCost;
    int damage;

    public Attack(String name, EnergyType type, int energyCost, int damage) {
        this.name = name;
        this.type = type;
        this.energyCost = energyCost;
        this.damage = damage;
    }

    public String getName() {
        return name;
    }

    public EnergyType getType() {
        return type;
    }

    public int getEnergyCost() {
        return energyCost;
    }

    public int getDamage() {
        return damage;
    }
}
