package src.models.util;

public enum PotStats {
    TOLERANCE("Tol");

    private final String tag;

    PotStats(String tag){
        this.tag = tag;
    }

    public String getTag(){
        return tag;
    }
}
