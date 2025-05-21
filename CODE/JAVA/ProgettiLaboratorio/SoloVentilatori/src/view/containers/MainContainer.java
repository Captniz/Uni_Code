package src.view.containers;

import javafx.scene.layout.BorderPane;

import src.models.UserData;

public class MainContainer extends BorderPane {
    private UserData user_data;
    private DataBar data_bar;
    private FunctionButtons f_buttons;
    private OrderingButtons o_buttons;
    private FanList fan_list;

    public MainContainer() {
        this.user_data = new UserData();
        this.data_bar = new DataBar(user_data);
        this.fan_list = new FanList(user_data, data_bar);
        this.f_buttons = new FunctionButtons(user_data,data_bar,fan_list);
        this.o_buttons = new OrderingButtons(fan_list);

        this.setTop(data_bar);
        this.setLeft(f_buttons);
        this.setRight(o_buttons);
        this.setCenter(fan_list);
    }
}
