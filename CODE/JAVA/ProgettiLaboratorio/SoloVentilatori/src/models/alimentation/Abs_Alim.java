package src.models.alimentation;

public abstract class Abs_Alim {
    public static enum Alim {
        MECCANICO("Meccanico"),
        BATTERIA("Batteria"),
        PRESA("Presa");

        private final String alimStr;

        Alim(String alimStr) {
            this.alimStr = alimStr;
        }

        public String getAlimStr() {
            return alimStr;
        }
    }

    abstract public int getAlimMult();
    abstract public Alim getAlimType();
}
