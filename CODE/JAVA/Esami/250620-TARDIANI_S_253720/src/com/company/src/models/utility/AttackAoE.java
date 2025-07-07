package com.company.src.models.utility;

public enum AttackAoE implements AttackSubtype{
        LOBBER( true),
        BLAST( false);

    private final boolean aereal;
    private final int range = 100;

        private AttackAoE(boolean aereal) {
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
