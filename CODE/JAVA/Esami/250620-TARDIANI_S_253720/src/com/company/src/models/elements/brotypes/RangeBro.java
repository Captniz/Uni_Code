package com.company.src.models.elements.brotypes;

import com.company.src.models.elements.attacktypes.AbsAttack;
import com.company.src.models.utility.RangeBros;

public class RangeBro extends AbsBro{
    public RangeBro(String name, RangeBros type, AbsAttack absAttack,int level) {
        super(name,type, absAttack,level);
    }
}
