package src.views.container;

import javafx.scene.layout.BorderPane;
import src.models.element.Player;

public class MainContainer extends BorderPane {
    private Player player;
    private List_Mutations list_mut;
    private Player_Mutations player_mut;
    private Stat_List stat_list;

    public MainContainer() {
        player = new Player();
        player_mut = new Player_Mutations(player);
        stat_list = new Stat_List(player);
        list_mut = new List_Mutations(player,stat_list,player_mut);
        updateView();
    }

    public void updateView() {
        this.getChildren().clear();

        this.setRight(player_mut);
        this.setLeft(stat_list);
        this.setBottom(list_mut);
    }
}
