package src.models;

import java.util.LinkedList;

public class UserData {
    private int money;
    private int monthly_cost;
    private int month;
    private LinkedList<Fan> subbed_fans;

    public UserData() {
        this.money = 100;
        this.monthly_cost = 0;
        this.month = 0;
        subbed_fans = new LinkedList<Fan>();
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    public void updateMoney(int amount) {
        this.money += amount;
    }

    public int getMonthly_cost() {
        return monthly_cost;
    }

    public void setMonthly_cost(int monthly_cost) {
        this.monthly_cost = monthly_cost;
    }

    public void updateMonthly_cost(int amount) {
        this.monthly_cost += amount;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public void incrementMonth() {
        this.month++;
    }

    public LinkedList<Fan> getFans(){
        return subbed_fans;
    }

    public void addFan(Fan fan){
        subbed_fans.add(fan);
        updateMonthly_cost(fan.getCosto());
    }

    public void removeFan(Fan fan){
        subbed_fans.remove(fan);
        updateMonthly_cost(-fan.getCosto());
    }

    public void removeCostlyFan(){
        LinkedList<Fan> tmp = subbed_fans;
        tmp.sort(new CostComparator());

        subbed_fans.remove(tmp.getLast());
    }
}
