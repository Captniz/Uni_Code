import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.Group;
import javafx.geometry.Insets;
import javafx.scene.layout.Pane;
import Quests.Compendium;
import UI.*;


public class Main extends Application {
    private Pane mainContainer = new VBox();
    private StatBar statBar = new StatBar();
    private Compendium compendium = new Compendium(statBar);
    private QuestDisplay questDisplay = new QuestDisplay(compendium);

    public static void main(String[] args) {
        launch(args);
    }
    
    @Override
    public void start(Stage primaryStage) throws Exception {

        mainContainer.setPadding(new Insets(10));
        mainContainer.getChildren().addAll(statBar, questDisplay);

        Group root = new Group(mainContainer);
        
        primaryStage.setTitle("The Examiner III, Wild Test");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }
}
