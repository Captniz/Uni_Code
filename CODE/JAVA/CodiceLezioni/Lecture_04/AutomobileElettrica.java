package Lecture_04;

public class AutomobileElettrica extends Automobile {
    // le auto elettriche han la batteria, di cui tracciamo lo stato qui
    boolean batterieCariche;

    // l'auto elettrica si ricarica, cosa che quella normale non puo` fare
    void ricarica() {
        batterieCariche = true;
    }

    // entrambe le auto si accendono, ma in modo diverso
    void accendi() {
        if (batterieCariche) {
            // SLIDE: super
            // MENTIMETER: cosa viene chiamato qui?
            super.accendi();
        } else accesa = false;
    }
    //back to main
}
