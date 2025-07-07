package com.company.src.models.elements.attacktypes;

import com.company.src.models.utility.AttackSubtype;

public class AbsAttack {
    String name;
    int baseDamage;
    int damage;
    AttackSubtype type;

    AbsAttack(){
        //Non ho capito se è il danno base o quello attuale il 10% in piu
        this.name = "";
        this.damage = 0;
        this.baseDamage = 0;
        this.type = null;
    }

    public AbsAttack(String name, int baseDamage, AttackSubtype type){
        this.name = name;
        this.baseDamage = baseDamage;
        this.damage = baseDamage;
        this.type = type;
    }

    public String getName() {
        return name;
    }

    public AttackSubtype getType() {
        return type;
    }

    public int getBaseDamage() {
        return baseDamage;
    }

    public void updateDamage(int damage) {
        this.damage += damage;
    }

    public int getDamage() {
        return damage;
    }
}
