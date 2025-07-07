package com.company.src.models.utility;

import com.company.src.models.elements.attacktypes.AoEAttack;
import com.company.src.models.elements.attacktypes.SingleAttack;
import com.company.src.models.elements.brotypes.AbsBro;
import com.company.src.models.elements.brotypes.RangeBro;
import com.company.src.models.elements.brotypes.TankBro;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class Compendium {
    public static final ArrayList<AbsBro> compendium = new ArrayList<>(
            Arrays.asList(
                    new TankBro("Franco",TankBros.TANK, new AoEAttack("SBAM",AttackAoE.BLAST,1000),2),
                    new RangeBro("Dinamichele",RangeBros.ARTILLERY, new AoEAttack("Bomba",AttackAoE.LOBBER,2000),8),
                    new RangeBro("Ape",RangeBros.SNIPER, new SingleAttack("Bzz",AttackSingle.SINGLE,2000),11),
                    new TankBro("Edoardo",TankBros.TANK, new SingleAttack("Sciarpa",AttackSingle.SINGLE,500),1),
                    new RangeBro("Salice",RangeBros.SNIPER, new AoEAttack("Tentacolo",AttackAoE.LOBBER,1200),1)
            )
    );
}
