package src;

import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.paint.Color;

public class Energy {
    public static enum EnergyType {
        WATER,
        FIRE,
        NEUTRAL,
        TENEBRAE
    }

    EnergyType type;

    Energy(EnergyType type) {
        this.type = type;
    }

    public EnergyType getType() {
        return type;
    }

    public Background getCorrespondingBg(){
        switch (this.type) {
            case FIRE:
                return new Background(new BackgroundFill(Color.FIREBRICK, null, null));
            case WATER:
                return new Background(new BackgroundFill(Color.AQUAMARINE, null, null));
            case TENEBRAE:
                return new Background(new BackgroundFill(Color.DARKVIOLET, null, null));
            case NEUTRAL:
                return new Background(new BackgroundFill(Color.HONEYDEW, null, null));
            default:
                return null;
        }
    }

    public static Background getCorrespondingBg(EnergyType type) {
        switch (type) {
            case FIRE:
                return new Background(new BackgroundFill(Color.FIREBRICK, null, null));
            case WATER:
                return new Background(new BackgroundFill(Color.AQUAMARINE, null, null));
            case TENEBRAE:
                return new Background(new BackgroundFill(Color.DARKVIOLET, null, null));
            case NEUTRAL:
                return new Background(new BackgroundFill(Color.HONEYDEW, null, null));
            default:
                return null;
        }
    }

    public static boolean compareEnergy(Energy e1, Energy e2) {
        if (e1.getType() == Energy.EnergyType.FIRE && e2.getType() == Energy.EnergyType.WATER) {
            return true;
        }
        if (e1.getType() == Energy.EnergyType.WATER && e2.getType() == Energy.EnergyType.FIRE) {
            return true;
        }
        if (e1.getType() == Energy.EnergyType.TENEBRAE) {
            return true;
        }
        return false;
    }

    public static boolean compareEnergy(EnergyType e1, EnergyType e2) {
        if (e1 == Energy.EnergyType.FIRE && e2 == Energy.EnergyType.WATER) {
            return true;
        }
        if (e1 == Energy.EnergyType.WATER && e2 == Energy.EnergyType.FIRE) {
            return true;
        }
        if (e1 == Energy.EnergyType.TENEBRAE) {
            return true;
        }
        return false;
    }
}
