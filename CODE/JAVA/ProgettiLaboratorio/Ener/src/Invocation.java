package src;

import src.Energy.EnergyType;

public class Invocation {
    public enum InvocationType {
        NORMAL,
        SUPREME
    }
    
    String name;
    int PV;
    int maxPV;
    int assignedEnergy;
    EnergyType type;
    Attack attack;
    InvocationType invocationType;

    public Invocation(String name, int PV, EnergyType type,InvocationType invocationType, Attack attack) {
        this.name = name;
        this.PV = PV;
        this.maxPV = PV;
        this.type = type;
        this.attack = attack;
        this.invocationType = invocationType;
        this.assignedEnergy = 0;
    }

    public String getName() {
        return name;
    }

    public int getPV() {
        return PV;
    }

    public int getMaxPV() {
        return maxPV;
    }

    public EnergyType getType() {
        return type;
    }
    public Attack getAttack() {
        return attack;
    }
    public InvocationType getInvocationType() {
        return invocationType;
    }
    public int getAssignedEnergy() {
        return assignedEnergy;
    }
    public void setAssignedEnergy(int assignedEnergy) {
        this.assignedEnergy = assignedEnergy;
    }
    public void damageFor(int damage, EnergyType type) {
        if (Energy.compareEnergy(type,this.type) == true) {
            this.PV -= damage*2;
        } else {
            this.PV -= damage;
        }
    }
}
