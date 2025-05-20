package Medicine;

import java.util.Date;

public class BanMedicine extends AbsMedicine {
    private boolean bought;

    public BanMedicine(String name, int cost, Date spoil) {
        super(name, cost, spoil, Type.BANCO);
    }

    public BanMedicine() {
        super();
    }

    public boolean isBought() {
        return bought;
    }

    public void buy() {
        this.bought = true;
    }
}
