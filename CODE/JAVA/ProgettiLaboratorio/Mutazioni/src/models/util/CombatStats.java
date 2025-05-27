package src.models.util;

public enum CombatStats {
    STRENGTH("Str"),
    VELOCITY("Vel");


    private final String tag;

    CombatStats(String tag){
        this.tag = tag;
    }

    public String getTag(){
        return tag;
    }
}
