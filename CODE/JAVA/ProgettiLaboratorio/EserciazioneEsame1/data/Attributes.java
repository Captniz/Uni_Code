package data;
import java.util.ArrayList;

import interfaces.*;

public class Attributes {
    public Statistics stats;
    protected ArrayList<StdMut> mutations;
    protected ArrayList<Spell> spells;    

    public Attributes() {
        stats = new Statistics();
        mutations = new ArrayList<StdMut>();
        spells = new ArrayList<Spell>();
    }

    public void addMutation(StdMut mutation) {
        mutations.add(mutation);
        mutation.applyMutation(this);
    }

    public void removeMutation(String mut_name) {
        for (int i = 0; i < mutations.size(); i++) {
            if (mutations.get(i).getName().equals(mut_name)) {
                mutations.get(i).removeMutation(this);
                mutations.remove(i);
                break;
            }
        }
    }

    public ArrayList<StdMut> getMutations() {
        return mutations;
    }

    public void addSpell(Spell spell) {
        spells.add(spell);
    }

    public void removeSpell(Spell spell) {
        spells.remove(spell);
    }

    public ArrayList<Spell> getSpells() {
        return spells;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Stats:\n");
        sb.append(stats.toString()).append("\n");
        sb.append("Mutations:\n");
        for (StdMut mutation : mutations) {
            sb.append(mutation.toString()).append("\n");
        }
        sb.append("Spells:\n");
        for (Spell spell : spells) {
            sb.append(spell.toString()).append("\n");
        }
        sb.append("End of Attributes\n");
        return sb.toString();
    }
}