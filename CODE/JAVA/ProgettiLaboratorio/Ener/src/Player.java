package src;

import java.util.LinkedList;

public class Player{
    LinkedList<Energy> energies;
    LinkedList<Invocation> invocations;

    public Player() {
        this.energies = new LinkedList<>();
        this.invocations = new LinkedList<>();
    }

    public void addNEnergy(int amount, Energy.EnergyType type) {
        for (int i = 0; i < amount; i++) {
            this.energies.add(new Energy(type));
        }
    }

    public void addMultipleEnergy(int fire, int water, int tenebrae, int neutral) {
        for (int i = 0; i < fire; i++) {
            this.energies.add(new Energy(Energy.EnergyType.FIRE));
        }
        for (int i = 0; i < water; i++) {
            this.energies.add(new Energy(Energy.EnergyType.WATER));
        }
        for (int i = 0; i < tenebrae; i++) {
            this.energies.add(new Energy(Energy.EnergyType.TENEBRAE));
        }
        for (int i = 0; i < neutral; i++) {
            this.energies.add(new Energy(Energy.EnergyType.NEUTRAL));
        }
    }

    public void addInvocation(Invocation invocation) {
        this.invocations.add(invocation);
    }

    public void setInvocations(LinkedList<Invocation> invocations) {
        this.invocations = invocations;
    }

    public LinkedList<Energy> getEnergies() {
        return energies;
    }

    public LinkedList<Invocation> getInvocations() {
        return invocations;
    }
}
