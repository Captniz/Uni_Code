package src.models.types;

public class Parete_Type extends Abs_Type{
    @Override
    public int getTypeCost() {
        return 20;
    }

    @Override
    public Types getType() {
        return Types.PARETE;
    }
}
