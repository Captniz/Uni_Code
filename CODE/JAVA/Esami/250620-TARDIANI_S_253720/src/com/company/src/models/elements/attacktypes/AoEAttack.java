package com.company.src.models.elements.attacktypes;

import com.company.src.models.utility.AttackAoE;

public class AoEAttack extends AbsAttack{
    public AoEAttack(String name, AttackAoE type, int baseDamage){
        super(name,baseDamage,type);
    }
}
