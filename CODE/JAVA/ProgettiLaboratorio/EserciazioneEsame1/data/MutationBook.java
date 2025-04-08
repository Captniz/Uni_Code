package data;

import interfaces.StdMut;
import mutations.*;

import java.util.HashMap;
import java.util.Map;

public class MutationBook {
    public enum MutationName {
        STRENGTH,
        SPEED,
        TOLLERANCE,
        FIRE,
        DEFENCE
    }
    
    private Map<MutationName, StdMut> spellBook = new HashMap<>();

    public MutationBook() {
        spellBook.put(MutationName.STRENGTH, new Strength());
        spellBook.put(MutationName.SPEED, new Speed());
        spellBook.put(MutationName.TOLLERANCE, new Tollerance());
        spellBook.put(MutationName.FIRE, new Fire());
        spellBook.put(MutationName.DEFENCE, new Defence());
    }

    public StdMut getMutation(MutationName name) {
        return spellBook.get(name);
    }



}
