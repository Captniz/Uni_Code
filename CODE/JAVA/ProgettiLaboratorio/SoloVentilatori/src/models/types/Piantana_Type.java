package src.models.types;

public class Piantana_Type extends Abs_Type{
    @Override
    public int getTypeCost() {
        return 10;
    }

    @Override
    public Types getType() {
        return Types.PIANTANA;
    }
}
