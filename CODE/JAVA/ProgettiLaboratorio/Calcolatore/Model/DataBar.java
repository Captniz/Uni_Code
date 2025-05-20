package Model;

import java.util.Date;

public class DataBar {
    private int money;
    private Date date;

    public DataBar(int money, Date date) {
        this.money = money;
        this.date = date;
    }

    public DataBar() {
        this.money = 0;
        this.date = new Date();
    }

    public void updateMoney(int money) {
        this.money += money;
    }

    public Date getDate() {
        return date;
    }

    public int getMoney() {
        return money;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public void setMoney(int money) {
        this.money = money;
    }
}
