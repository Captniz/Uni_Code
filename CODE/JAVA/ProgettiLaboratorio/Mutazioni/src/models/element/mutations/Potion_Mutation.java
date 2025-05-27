package src.models.element.mutations;

import java.util.HashMap;

import src.models.element.Player;
import src.models.util.MutTypes;
import src.models.util.PotStats;

public class Potion_Mutation extends Abs_Mutation{
    private HashMap<PotStats, Integer> stats;


    public Potion_Mutation(String name,HashMap<PotStats, Integer> stats){
        super(name,MutTypes.POTION);
        this.stats = stats;
    }

    @Override
    public void applyMutation(Player pl) {
        stats.forEach((key,val) -> {
            pl.updatePotStat(key, stats.get(key));
        });
    }

    @Override
    public void removeMutation(Player pl) {
        stats.forEach((key,val) -> {
            pl.updatePotStat(key, -stats.get(key));
        });
    }


}
