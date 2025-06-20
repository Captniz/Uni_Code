package models.elements;

import models.util.Bonus;
import models.util.Letters;

public class Cell {
    Letters letter;
    Bonus bonus;

    public Cell(Letters letter, Bonus bonus){
        this.letter = letter;
        this.bonus = bonus;
    }
    public Cell(Letters letter){
        this.letter = letter;
        this.bonus = null;
    }

    public void setBonus(Bonus bonus) {
        this.bonus = bonus;
    }

    public String getLetterS() {
        return letter.toString();
    }

    public String getBonusS() {
        return bonus.toString();
    }

    public Letters getLetter() {
        return letter;
    }

    public Bonus getBonus() {
        return bonus;
    }
}
