package Recipe;

import java.util.Date;

import Medicine.AbsMedicine;
import Medicine.RecMedicine;

public class Recipe {
    AbsMedicine medicine;
    String medName;
    Date expirationDate;
    int uses;
    boolean expired;

    public Recipe(AbsMedicine medicine, Date expirationDate) {
        this.medicine = medicine;
        this.expirationDate = expirationDate;
        this.uses = 0;

        if (expirationDate.before(new Date())) {
            this.expired = true;
        } else {
            this.expired = false;
        }

        this.medName = medicine.getName();
    }

    public Recipe(String medName, Date expirationDate) {
        this.medicine = null;
        this.expirationDate = expirationDate;
        this.uses = 0;

        if (expirationDate.before(new Date())) {
            this.expired = true;
        } else {
            this.expired = false;
        }

        this.medName = medName;
    }

    public Date getExpirationDate() {
        return expirationDate;
    }

    public int getUses() {
        return uses;
    }

    public boolean isExpired() {
        return expired;
    }

    public void expire() {
        this.expired = true;
    }

    public void setUses(int uses) {
        this.uses = uses;
    }

    public boolean use() {
        if (medicine != null) {
            if (uses >= ((RecMedicine) medicine).getUses()) {
                return true; // medicine has been used up
            } else {
                uses++;
                return false;
            }
        }
        return false;
    }

    public String getMedicineName() {
        return medName;
    }
}
