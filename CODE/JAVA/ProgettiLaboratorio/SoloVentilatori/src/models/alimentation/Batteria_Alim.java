package src.models.alimentation;

public class Batteria_Alim extends Abs_Alim {
    @Override
    public int getAlimMult(){
        return 3;
    };

    @Override
    public Alim getAlimType(){
        return Alim.BATTERIA;
    };
}
