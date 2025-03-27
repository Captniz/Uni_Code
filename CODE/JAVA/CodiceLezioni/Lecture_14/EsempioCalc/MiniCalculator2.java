package Lecture_14.EsempioCalc;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.TilePane;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;

public class MiniCalculator2 extends Application {
    final TextField input1 = new TextField("");
    final TextField input2 = new TextField("");
    final NonEditableTextField output = new NonEditableTextField("");

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("MiniCalculator");
        BorderPane borderP = new BorderPane();
        // ======== Top
        Label lt = new Label("MiniCalculator");
        lt.setFont(Font.font("Verdana", FontWeight.BOLD, 36));
        borderP.setTop(lt);
        BorderPane.setAlignment(lt, Pos.CENTER);
        // ======== Right
        Button clear = new Button("Clear");
        clear.setMinWidth(100.0);
        borderP.setRight(clear);
        BorderPane.setAlignment(clear, Pos.CENTER);
        clear.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                input1.clear();
                input2.clear();
                output.clear();
            }
        });
        // ======== Left
        Label lableft = new Label("left");
        lableft.setMinWidth(100.0);
        borderP.setLeft(lableft);
        BorderPane.setAlignment(lableft, Pos.CENTER_LEFT);
        // ======== Bottom
        Label lb = new Label("© magicSoftware ");
        lb.setFont(Font.font("Times", FontPosture.ITALIC, 16));
        borderP.setBottom(lb);
        BorderPane.setAlignment(lb, Pos.BOTTOM_RIGHT);
        // ======== Center
        final TilePane box = new TilePane();
        box.setPrefColumns(1);
        final TilePane hb = new TilePane();
        hb.setAlignment(Pos.CENTER);
        final OperationButton sum = new OperationButton(this, "PIU", "+");
        final OperationButton divide = new OperationButton(this, "DIVISO", "/");
        final OperationButton multiply = new OperationButton(this, "PER", "*");
        final OperationButton subtract = new OperationButton(this, "MENO", "-");
        // ----
        hb.getChildren().addAll(sum, subtract, multiply, divide);
        box.getChildren().addAll(input1, input2, hb, output);
        // ======== Behaviour
        borderP.setCenter(box);
        Scene scene = new Scene(borderP);
        scene.addEventFilter(KeyEvent.KEY_TYPED, new KBFilter(this));
        primaryStage.setScene(scene);
        primaryStage.sizeToScene();
        primaryStage.widthProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> ov, Number oldValue, Number newValue) {
                double w = newValue.doubleValue() * 3 / 5;
                box.setMaxWidth(w);
                box.setMinWidth(w);
                hb.setMaxWidth(w);
                hb.setMinWidth(w);
                double iw = Math.floor(w / 4);
                sum.setOBwidth(iw);
                subtract.setOBwidth(iw);
                divide.setOBwidth(iw);
                multiply.setOBwidth(iw);
            }
        });
        primaryStage.show();
    }

    public void compute(String operator) {
        double o1, o2;
        try {
            o1 = Double.parseDouble(input1.getText());
            o2 = Double.parseDouble(input2.getText());
        } catch (NumberFormatException e) {
            Label msg = new Label("Errore - Not A Number!");
            StackPane g = new StackPane();
            g.getChildren().add(msg);
            Scene stageScene = new Scene(g, 300, 200);
            Stage errorStage = new Stage();
            errorStage.setScene(stageScene);
            errorStage.show();
            return;
        }
        switch (operator) {
            case "+":
                output.setText("" + (o1 + o2)); break;
            case "*":
                output.setText("" + (o1 * o2)); break;
            case "-":
                output.setText("" + (o1 - o2)); break;
            case "/":
                output.setText("" + (o1 / o2)); break;
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}

