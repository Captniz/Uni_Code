package src.models.alimentation;

public class Presa_Alim extends Abs_Alim {
    @Override
    public int getAlimMult(){
        return 2;
    };

    @Override
    public Alim getAlimType(){
        return Alim.PRESA;
    };
}
