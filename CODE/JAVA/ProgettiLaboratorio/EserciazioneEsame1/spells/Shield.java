package spells;

import interfaces.*;

public class Shield implements Spell {

    public Shield() {
    }

    public void castSpell() {
        System.out.println("Casting Shied!");
    }

    public String getName() {
        return "Shield";
    }
}
