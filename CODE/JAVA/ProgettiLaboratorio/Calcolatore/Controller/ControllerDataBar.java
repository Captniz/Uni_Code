package Controller;

import Model.DataBar;
import View.ViewDataBar;

public class ControllerDataBar {
    private DataBar logic;
    private ViewDataBar view;

    public ControllerDataBar(DataBar logic, ViewDataBar view) {
        this.logic = logic;
        this.view = view;
    }

    public ControllerDataBar() {
        this.logic = new DataBar();
        this.view = new ViewDataBar();
    }

    public ControllerDataBar(int money) {
        this.logic = new DataBar();
        this.view = new ViewDataBar();
        updateBar(money);
    }

    public ControllerDataBar(ViewDataBar view) {
        this.logic = new DataBar();
        this.view = view;
    }

    public void updateBar(int money) {
        logic.updateMoney(money);
        view.updateBar(logic.getMoney(), logic.getDate());
    }

    public int getMoney() {
        return logic.getMoney();
    }

    public DataBar getLogic() {
        return logic;
    }

    public ViewDataBar getView() {
        return view;
    }
}
