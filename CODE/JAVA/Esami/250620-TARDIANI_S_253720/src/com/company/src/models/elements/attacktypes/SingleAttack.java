package com.company.src.models.elements.attacktypes;

import com.company.src.models.utility.AttackSingle;

public class SingleAttack extends AbsAttack{
    public SingleAttack(String name, AttackSingle type, int baseDamage){
        super(name,baseDamage,type);
    }
}
