package mutations;

import interfaces.*;
import spells.Fireball;

import java.util.ArrayList;

import data.Attributes;

public class Fire implements SpellMut, StdMut {
    public Fire() {
    }

    @Override
    public void applyMutation(Attributes attr) {
        applySpell(attr.getSpells());
    }

    @Override
    public void removeMutation(Attributes attr) {
        removeSpell(attr.getSpells());
    }

    @Override
    public void applySpell(ArrayList<Spell> spells) {
        spells.add(new Fireball());
    }

    @Override
    public void removeSpell(ArrayList<Spell> spells) {
        for (int i = 0; i < spells.size(); i++) {
            if (spells.get(i).getName().equals("Fireball")) {
                spells.remove(i);
                break;
            }
        }
    }

    @Override
    public String getName() {
        return "Fire";
    }
}
