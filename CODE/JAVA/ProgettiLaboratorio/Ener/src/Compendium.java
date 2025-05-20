package src;

import java.util.Arrays;
import java.util.LinkedList;

public class Compendium {
    public final static LinkedList<Invocation> invocations = new LinkedList<>(
        Arrays.asList(
            new Invocation(
                "Ifrit", 
                30, 
                Energy.EnergyType.FIRE, 
                Invocation.InvocationType.NORMAL,
                new Attack(
                    "Hellflame", 
                    Energy.EnergyType.FIRE, 
                    2, 
                    20
                )
            ),
            new Invocation(
                "Phoenix", 
                50, 
                Energy.EnergyType.FIRE, 
                Invocation.InvocationType.SUPREME,
                new Attack(
                    "Fiammata", 
                    Energy.EnergyType.FIRE, 
                    2, 
                    20
                )
            ),
            new Invocation(
                "Diablos", 
                50, 
                Energy.EnergyType.TENEBRAE, 
                Invocation.InvocationType.NORMAL,
                new Attack(
                    "Demi", 
                    Energy.EnergyType.TENEBRAE, 
                    1, 
                    20
                )
            ),
            new Invocation(
                "Leviathan", 
                30, 
                Energy.EnergyType.WATER, 
                Invocation.InvocationType.NORMAL,
                new Attack(
                    "Tsunami", 
                    Energy.EnergyType.WATER, 
                    1, 
                    10
                )
            ),
            new Invocation(
                "Bahamut", 
                60, 
                Energy.EnergyType.NEUTRAL, 
                Invocation.InvocationType.SUPREME,
                new Attack(
                    "MegaFlare", 
                    Energy.EnergyType.NEUTRAL, 
                    3, 
                    40
                )
            ),
            new Invocation(
                "Alexander", 
                30, 
                Energy.EnergyType.NEUTRAL, 
                Invocation.InvocationType.NORMAL,
                new Attack(
                    "Judgement", 
                    Energy.EnergyType.NEUTRAL, 
                    1, 
                    10
                )
            )
        )
    );
}
