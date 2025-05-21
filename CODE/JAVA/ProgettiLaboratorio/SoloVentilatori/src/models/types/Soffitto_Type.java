package src.models.types;

public class Soffitto_Type extends Abs_Type{
    @Override
    public int getTypeCost() {
        return 2;
    }

    @Override
    public Types getType() {
        return Types.SOFFITTO;
    }
}
