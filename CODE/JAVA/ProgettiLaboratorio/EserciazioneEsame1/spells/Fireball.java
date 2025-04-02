package spells;

import interfaces.*;

public class Fireball implements Spell {

    public Fireball() {
    }

    public void castSpell() {
        System.out.println("Casting Fireball!");
    }

    public String getName() {
        return "Fireball";
    }
}
