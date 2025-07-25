import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.Group;
import views.containers.MainContainer;

public class Main extends Application {
    final int WIDTH = 280;
    final int HEIGHT = 500;
    final MainContainer mainContainer = new MainContainer();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        mainContainer.setPrefSize(WIDTH, HEIGHT);

        Group root = new Group(mainContainer);

        primaryStage.setWidth(WIDTH);
        primaryStage.setHeight(HEIGHT);

        primaryStage.setTitle("Hello");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }
}
