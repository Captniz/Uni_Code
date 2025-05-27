package src.models.element;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedList;

import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import src.models.element.spells.Abs_Spell;
import src.models.element.mutations.*;
import src.models.util.*;

public class Player {
    private int level;
    private HashMap<CombatStats, Integer> combatStats;
    private HashMap<PotStats, Integer> potionStats;
    private LinkedHashMap<MutTypes, Abs_Mutation[]> mutations;
    private LinkedList<Abs_Spell> spells;

    static final int combat_cap = 1;
    static final int potion_cap = 1;
    static final int spell_cap = 1;
    static final int free_cap = 1;

    public Player() {
        level = 0;

        combatStats = new HashMap<CombatStats, Integer>();
        combatStats.put(CombatStats.STRENGTH, 10);
        combatStats.put(CombatStats.VELOCITY, 10);

        potionStats = new HashMap<PotStats, Integer>();
        potionStats.put(PotStats.TOLERANCE, 2);

        mutations = new LinkedHashMap<MutTypes, Abs_Mutation[]>();
        mutations.put(MutTypes.COMBAT, new Combat_Mutation[combat_cap]);
        mutations.put(MutTypes.SPELL, new Spell_Mutation[spell_cap]);
        mutations.put(MutTypes.POTION, new Potion_Mutation[potion_cap]);
        mutations.put(MutTypes.FREE, new Abs_Mutation[free_cap]);
        spells = new LinkedList<Abs_Spell>();
    }

    public int getLevel() {
        return level;
    }

    public int getStrength() {
        return combatStats.get(CombatStats.STRENGTH);
    }

    public int getVelocity() {
        return combatStats.get(CombatStats.VELOCITY);
    }

    public int getTolerance() {
        return potionStats.get(PotStats.TOLERANCE);
    }

    public void setStrength(int strength) {
        combatStats.put(CombatStats.STRENGTH, strength);
    }

    public void setVelocity(int velocity) {
        combatStats.put(CombatStats.VELOCITY, velocity);
    }

    public void setTolerance(int tolerance) {
        potionStats.put(PotStats.TOLERANCE, tolerance);
    }

    public void updateStrength(int strength) {
        combatStats.replace(CombatStats.STRENGTH, combatStats.get(CombatStats.STRENGTH) + strength);
    }

    public void updateVelocity(int velocity) {
        combatStats.replace(CombatStats.VELOCITY, combatStats.get(CombatStats.VELOCITY) + velocity);
    }

    public void updateTolerance(int tolerance) {
        potionStats.replace(PotStats.TOLERANCE, potionStats.get(PotStats.TOLERANCE) + tolerance);
    }

    public void updatePotStat(PotStats key, int val) {
        potionStats.replace(key, potionStats.get(key) + val);
    }

    public void updateCombatStat(CombatStats key, int val) {
        combatStats.replace(key, combatStats.get(key) + val);
    }

    public LinkedHashMap<MutTypes, Abs_Mutation[]> getMutations() {
        return mutations;
    }

    public LinkedList<Abs_Spell> getSpells() {
        return spells;
    }

    public void addSpell(Abs_Spell spell) {
        spells.add(spell);
    }

    public void removeSpell(Abs_Spell spell) {
        spells.remove(spell);
    }

    public boolean addMutation(Abs_Mutation mut) {
        MutTypes type = mut.getType();
        Abs_Mutation[] mut_arr = mutations.get(type);

        for (int i = 0; i < mut_arr.length; i++) {
            if (mut_arr[i] == null) {
                mut_arr[i] = mut;
                mut.applyMutation(this);
                return true;
            }
        }

        mut_arr = mutations.get(MutTypes.FREE);
        for (int i = 0; i < mut_arr.length; i++) {
            if (mut_arr[i] == null) {
                mut_arr[i] = mut;
                mut.applyMutation(this);
                return true;
            }
        }

        Alert alert = new Alert(AlertType.ERROR);
        alert.setContentText("Impossibile aggiungere mutazione : slot pieni");
        alert.showAndWait();
        return false;
    }

    public boolean removeMutation(Abs_Mutation mut) {
        MutTypes type = mut.getType();
        Abs_Mutation[] mut_arr = mutations.get(type);

        for (int i = 0; i < mut_arr.length; i++) {
            if (mut_arr[i] != null && mut_arr[i].equals(mut)) {
                mut_arr[i] = null;
                mut.removeMutation(this);
                return true;
            }
        }

        mut_arr = mutations.get(MutTypes.FREE);
        for (int i = 0; i < mut_arr.length; i++) {
            if (mut_arr[i] != null && mut_arr[i].equals(mut)) {
                mut_arr[i] = null;
                mut.removeMutation(this);
                return true;
            }
        }

        Alert alert = new Alert(AlertType.ERROR);
        alert.setContentText("Impossibile rimuovere mutazione : non trovata");
        alert.showAndWait();
        return false;
    }

    public boolean hasMutation(Abs_Mutation mut) {
        MutTypes type = mut.getType();

        for (Abs_Mutation player_mut : mutations.get(type)) {
            if (player_mut != null && player_mut.equals(mut)) {
                return true;
            }
        }

        for (Abs_Mutation player_mut : mutations.get(MutTypes.FREE)) {
            if (player_mut != null && player_mut.equals(mut)) {
                return true;
            }
        }

        return false;
    }
}
