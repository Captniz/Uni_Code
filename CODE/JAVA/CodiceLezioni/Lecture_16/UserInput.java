package Lecture_16;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.TilePane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;


public class UserInput extends Application {

    private static final double BWIDTH = 100;
    private static final double SPACING = 10;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Label lNome = new Label("Nome: ");
        Label lEta = new Label("Età: ");
        TextField tNome = new TextField();
        TextField tEta = new TextField();
        Button ok = new Button("OK");
        Button clear = new Button("Clear");
        Button cancel = new Button("Cancel");
        ok.setMinWidth(BWIDTH);
        clear.setMinWidth(BWIDTH);
        cancel.setMinWidth(BWIDTH);

        tNome.setPromptText("Inserisci il tuo nome");
        tEta.setPromptText("Inserisci la tua età");

        HBox hNome = new HBox(lNome,tNome);
        HBox hEta = new HBox(lEta,tEta);
        hNome.setAlignment(Pos.CENTER_RIGHT);
        hEta.setAlignment(Pos.CENTER_RIGHT);
        TilePane buttons = new TilePane(ok,clear,cancel);
        buttons.setHgap(10);
        buttons.setPrefColumns(3);
        VBox root2 = new VBox(hNome,hEta,buttons);
        root2.setSpacing(SPACING);
        root2.setPadding(new Insets(SPACING));
        Scene scene2 = new Scene(root2);
        Stage stage2 = new Stage();
        stage2.setTitle("Enter your data");
        stage2.setScene(scene2);

        ok.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                String nome = tNome.getText();
                String eta = tEta.getText();
                Alert alert;
                if (nome.isBlank() || eta.isBlank() || !isInteger(eta)) {
                    alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Errore!");
                    alert.setHeaderText("Input non corretto");
                    if (nome.isBlank() || eta.isBlank()) {
                        alert.setContentText("Non hai inserito tutti i dati.");
                    }else {
                        alert.setContentText("L'età non è un valore intero.");
                    }
                } else {
                    alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Risultato");
                    alert.setHeaderText("Input corretto");
                    alert.setContentText("Mi chiamo " + nome + " e ho " + eta + " anni.");
                }
                alert.showAndWait();
            }
        }
        );

        clear.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
            tNome.clear();
            tEta.clear();
        }});

        cancel.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
            stage2.close();
        }});

        Button button = new Button("Input data");
        button.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent actionEvent) {
                stage2.show();
            }});

        StackPane root = new StackPane(button);
        primaryStage.setTitle("User Input");
        primaryStage.setScene(new Scene(root, 300, 275));
        primaryStage.show();
    }


    private boolean isInteger(String s) {
        for (char c : s.toCharArray())
            if (!Character.isDigit(c))
                return false;
        return true;
    }
    // provate entrambi
    private boolean isInteger2(String s) {
        try {
            Integer.parseInt(s);
            return true;
        } catch (NumberFormatException nme) {
            return false;
        }
    }
}
