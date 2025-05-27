package src.models.element.mutations;

import java.util.HashMap;

import src.models.element.Player;
import src.models.util.CombatStats;
import src.models.util.MutTypes;

public class Combat_Mutation extends Abs_Mutation{
    private HashMap<CombatStats, Integer> stats;


    public Combat_Mutation(String name, HashMap<CombatStats, Integer> stats){
        super(name,MutTypes.COMBAT);
        this.stats = stats;
    }

    @Override
    public void applyMutation(Player pl) {
        stats.forEach((key,val) -> {
            pl.updateCombatStat(key, stats.get(key));
        });
    }

    @Override
    public void removeMutation(Player pl) {
        stats.forEach((key,val) -> {
            pl.updateCombatStat(key, -stats.get(key));
        });
    }
}
