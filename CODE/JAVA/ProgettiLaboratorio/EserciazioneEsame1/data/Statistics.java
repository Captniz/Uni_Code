package data;
import java.util.HashMap;

public class Statistics {
    private int strength;
    private int dexterity;
    private int intelligence;
    private int wisdom;
    private int charisma;
    private int constitution;

    public Statistics() {
        this.strength = 0;
        this.dexterity = 0;
        this.intelligence = 0;
        this.wisdom = 0;
        this.charisma = 0;
        this.constitution = 0;
    }

    public Statistics(int strength, int dexterity, int intelligence, int wisdom, int charisma, int constitution) {
        this.strength = strength;
        this.dexterity = dexterity;
        this.intelligence = intelligence;
        this.wisdom = wisdom;
        this.charisma = charisma;
        this.constitution = constitution;
    }

    public int getStrength() {
        return strength;
    }

    public void setStrength(int strength) {
        this.strength = strength;
    }

    public int getDexterity() {
        return dexterity;
    }

    public void setDexterity(int dexterity) {
        this.dexterity = dexterity;
    }

    public int getIntelligence() {
        return intelligence;
    }

    public void setIntelligence(int intelligence) {
        this.intelligence = intelligence;
    }

    public int getWisdom() {
        return wisdom;
    }

    public void setWisdom(int wisdom) {
        this.wisdom = wisdom;
    }

    public int getCharisma() {
        return charisma;
    }

    public void setCharisma(int charisma) {
        this.charisma = charisma;
    }

    public int getConstitution() {
        return constitution;
    }

    public void setConstitution(int constitution) {
        this.constitution = constitution;
    }

    public void overrideStats(Statistics stats) {
        this.strength += stats.getStrength();
        this.dexterity += stats.getDexterity();
        this.intelligence += stats.getIntelligence();
        this.wisdom += stats.getWisdom();
        this.charisma += stats.getCharisma();
        this.constitution += stats.getConstitution();
    }

    public void resetStats() {
        this.strength = 0;
        this.dexterity = 0;
        this.intelligence = 0;
        this.wisdom = 0;
        this.charisma = 0;
        this.constitution = 0;
    }

    public HashMap<String, Integer> getStats() {
        HashMap<String, Integer> stats = new HashMap<>();
        stats.put("strength", strength);
        stats.put("dexterity", dexterity);
        stats.put("intelligence", intelligence);
        stats.put("wisdom", wisdom);
        stats.put("charisma", charisma);
        stats.put("constitution", constitution);
        return stats;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Strength: ").append(strength).append("\n");
        sb.append("Dexterity: ").append(dexterity).append("\n");
        sb.append("Intelligence: ").append(intelligence).append("\n");
        sb.append("Wisdom: ").append(wisdom).append("\n");
        sb.append("Charisma: ").append(charisma).append("\n");
        sb.append("Constitution: ").append(constitution).append("\n");
        return sb.toString();
    }
}