package src.models.types;

public abstract class Abs_Type {
    public static enum Types {
        PIANTANA(1, "Piantana"),
        PARETE(2, "Parete"),
        SOFFITTO(3, "Soffitto");

        private final int priority;
        private final String typeStr;

        Types(int priority, String typeStr) {
            this.priority = priority;
            this.typeStr = typeStr;
        }

        public int getPriority() {
            return priority;
        }

        public String getTypeStr() {
            return typeStr;
        }
    }

    abstract public int getTypeCost();

    abstract public Types getType();
}