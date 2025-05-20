
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.Group;
import src.GameTable;

public class Main extends Application {
    final int WIDTH = 600;
    final int HEIGHT = 600;
    GameTable mainContainer;

    public static void main(String[] args) {
        launch(args);
    }
    
    @Override
    public void start(Stage primaryStage) {
        mainContainer = new GameTable();

        mainContainer.setPrefSize(WIDTH, HEIGHT);

        Group root = new Group(mainContainer);
        
        primaryStage.setWidth(WIDTH);
        primaryStage.setHeight(HEIGHT);
        
        primaryStage.setTitle("Hello");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }
}
