package src.views.container;

import javafx.scene.layout.VBox;
import src.models.element.Compendium;
import src.models.element.Player;
import src.models.element.mutations.Abs_Mutation;
import src.views.element.Mutation_View;
import javafx.event.EventHandler;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;

public class List_Mutations extends VBox {

    private Player player;
    private ActualList list;
    private Stat_List stat_list;
    private Player_Mutations player_mut;

    public List_Mutations(Player player, Stat_List stat_list, Player_Mutations player_mut) {
        this.player = player;
        this.stat_list = stat_list;
        this.player_mut = player_mut;
        list = new ActualList();

        updateView();
    }

    public void updateView() {
        this.getChildren().clear();

        list.updateView();
        this.getChildren().add(new Label("Mutazioni Possibili"));
        this.getChildren().add(list);
    }

    class ActualList extends HBox {
        public void updateView() {
            this.getChildren().clear();
            for (Abs_Mutation mut : Compendium.mutations) {
                boolean isActive = player.hasMutation(mut);

                Mutation_View m_view = new Mutation_View(mut, isActive);
                m_view.setOnMouseClicked(new MutationToggle());
                this.getChildren().add(m_view);
            }
        }
    }

    class MutationToggle implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent event) {
            Mutation_View view = (Mutation_View) event.getSource();
            Abs_Mutation mut = view.getMutation();

            if (view.getIsActive()) {
                if (!player.removeMutation(mut))
                    return;
            } else {
                if (!player.addMutation(mut))
                    return;
            }

            list.updateView();
            player_mut.updateView();
            stat_list.updateView();
        }

    }
}
