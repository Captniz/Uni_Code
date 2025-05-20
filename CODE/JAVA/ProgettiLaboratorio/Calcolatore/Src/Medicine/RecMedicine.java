package Medicine;

import java.util.Date;

public class RecMedicine extends AbsMedicine {
    private int uses;
    private int discount;

    public RecMedicine(String name, int cost, Date spoil, int uses) {
        super(name, cost-((uses > 1) ? 5 : 10), spoil, Type.RICETTA);
        this.uses = uses;
        this.discount = (uses > 1) ? 5 : 10;
    }

    public RecMedicine() {
        super();
        this.uses = 0;
        this.discount = 0;
    }

    public int getUses() {
        return uses;
    }

    public int getDiscount() {
        return discount;
    }

    public int getStandardCost() {
        return cost + discount;
    }
}
