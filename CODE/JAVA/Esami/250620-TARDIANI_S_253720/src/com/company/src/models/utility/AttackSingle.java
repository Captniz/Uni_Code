package com.company.src.models.utility;

public enum AttackSingle implements AttackSubtype{
    SINGLE(false);

    private final boolean aereal;
    private final int range = 150;

    private AttackSingle(boolean aereal) {
        this.aereal = aereal;
    }

    @Override
    public boolean getAereal() {
        return false;
    }

    @Override
    public int getRange() {
        return range;
    }
}