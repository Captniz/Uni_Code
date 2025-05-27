package src.models.element;

import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

import src.models.element.mutations.*;
import src.models.element.spells.Abs_Spell;
import src.models.util.*;

public interface Compendium {
        final static LinkedList<Abs_Spell> spells = new LinkedList<>(
                        Arrays.asList(
                                        new Abs_Spell("Igni"),
                                        new Abs_Spell("Quen")));

        final static LinkedList<Abs_Mutation> mutations = new LinkedList<Abs_Mutation>(
                        Arrays.asList(
                                        new Combat_Mutation("Str", new HashMap<CombatStats, Integer>(Map.of(
                                                        CombatStats.STRENGTH, 2))),
                                        new Combat_Mutation("Vel", new HashMap<CombatStats, Integer>(Map.of(
                                                        CombatStats.VELOCITY, 2))),
                                        new Potion_Mutation("Tol", new HashMap<PotStats, Integer>(Map.of(
                                                        PotStats.TOLERANCE, 2))),
                                        new Spell_Mutation("Igni", spells.get(0)),
                                        new Spell_Mutation("Quen", spells.get(1))));
}
