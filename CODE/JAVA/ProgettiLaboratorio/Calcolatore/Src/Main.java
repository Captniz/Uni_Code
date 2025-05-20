
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.Group;
import javafx.scene.layout.BorderPane;

import java.util.LinkedList;

import Controller.ControllerDataBar;

import java.util.Arrays;
import java.util.Date;
import View.*;
import Medicine.*;
import Recipe.Recipe;


public class Main extends Application {
    final int WIDTH = 1000;
    final int HEIGHT = 600;

    final Date tomorrow = new Date(new Date().getTime() + 1000000000);
    final Date yesterday = new Date(new Date().getTime() - 1000000000);

    final LinkedList<ViewMedicine> medicines = new LinkedList<ViewMedicine>(
        Arrays.asList(
            new ViewMedicine(new BanMedicine("Benagol", 10, tomorrow)),
            new ViewMedicine(new BanMedicine("Brufen200", 8, tomorrow)),
            new ViewMedicine(new RecMedicine("Brufen800", 20, tomorrow, 1)),
            new ViewMedicine(new RecMedicine("Oki", 12, tomorrow, 4)),
            new ViewMedicine(new RecMedicine("Fluifort", 18, yesterday, 2)),
            new ViewMedicine(new RecMedicine("Tachiprina1000", 6, tomorrow, 3))
        )
    );

    final LinkedList<ViewRecipe> recipes = new LinkedList<ViewRecipe>(
        Arrays.asList(
            new ViewRecipe(new Recipe("Brufen800", yesterday)),
            new ViewRecipe(new Recipe(medicines.get(4).getMedicine(),tomorrow)),
            new ViewRecipe(new Recipe(medicines.get(5).getMedicine(),tomorrow))
        )
    );

    private BorderPane mainContainer = new BorderPane();
    private ControllerDataBar dataBar = new ControllerDataBar(100);
    private ViewMedicineDetail medicineDetail = new ViewMedicineDetail(dataBar, recipes);
    private ViewRecipeList recipeList = new ViewRecipeList(recipes, medicineDetail);
    private ViewMedicineList medicineList = new ViewMedicineList(medicines, medicineDetail);

    public static void main(String[] args) {
        launch(args);
    }
    
    @Override
    public void start(Stage primaryStage) throws Exception {
        mainContainer.setPrefSize(WIDTH, HEIGHT);

        mainContainer.setBottom(dataBar.getView());
        mainContainer.setCenter(medicineDetail);
        mainContainer.setLeft(medicineList);
        mainContainer.setRight(recipeList);

        Group root = new Group(mainContainer);
        
        primaryStage.setTitle("Farmacia");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }
}
