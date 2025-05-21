package src.models.alimentation;

public class Meccanico_Alim extends Abs_Alim {
    @Override
    public int getAlimMult(){
        return 1;
    };

    @Override
    public Alim getAlimType(){
        return Alim.MECCANICO;
    };
}
