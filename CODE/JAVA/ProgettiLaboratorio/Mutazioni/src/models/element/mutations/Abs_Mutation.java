package src.models.element.mutations;

import src.models.element.Player;
import src.models.util.MutTypes;

public abstract class Abs_Mutation {
    private String name;
    private MutTypes type;

    public Abs_Mutation(String name, MutTypes type) {
        this.name = name;
        this.type = type;
    }

    public String getName() {
        return name;
    }

    public MutTypes getType() {
        return type;
    }

    public abstract void applyMutation(Player pl);

    public abstract void removeMutation(Player pl);
}
