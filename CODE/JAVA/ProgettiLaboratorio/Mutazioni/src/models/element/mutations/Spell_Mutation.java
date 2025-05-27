package src.models.element.mutations;

import src.models.element.Player;
import src.models.element.spells.Abs_Spell;
import src.models.util.MutTypes;

public class Spell_Mutation extends Abs_Mutation {
    private Abs_Spell spell;

    public Spell_Mutation(String name, Abs_Spell spell) {
        super(name, MutTypes.SPELL);
        this.spell = spell;
    }

    public Abs_Spell getSpell() {
        return spell;
    }

    @Override
    public void applyMutation(Player pl) {
        pl.addSpell(spell);
    }

    @Override
    public void removeMutation(Player pl) {
        pl.removeSpell(spell);
    }    
}
