package com.company.src.models.elements.brotypes;

import com.company.src.models.elements.attacktypes.AbsAttack;
import com.company.src.models.utility.TankBros;

public class TankBro extends AbsBro{
    public TankBro(String name, TankBros type, AbsAttack absAttack, int level) {
        super(name,type, absAttack,level);
    }
}
