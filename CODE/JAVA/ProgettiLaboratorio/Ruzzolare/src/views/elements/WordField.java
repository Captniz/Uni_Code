package views.elements;

import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import models.util.Dictionary;

public class WordField extends HBox implements View{
    private Button find;
    private String word;

    public WordField(){
        super();
        word = "";
        find = new Button("Find");
        find.setOnMouseClicked(new FindWord(this));
        this.getChildren().addAll(find, new Text());
        updateView();
    }

    @Override
    public void updateView() {
        this.getChildren().remove(this.getChildren().getLast());
        this.getChildren().add(new Text("Parola Corrente : "+word));
    }

    public void updateWord(String word){
        this.word = word;
        updateView();
    }

    public void concatWord(String word){
        this.word += word;
        updateView();
    }

    public void clearWord(){
        this.word = "";
        updateView();
    }

    public String getWord() {
        return word;
    }

    static class FindWord implements EventHandler<MouseEvent> {
        WordField wordField;
        public FindWord(WordField word){
            wordField=word;
        }

        @Override
        public void handle(MouseEvent event){
            for (Dictionary finds : Dictionary.values()){
                if (finds.toString().equals(wordField.getWord())){

                }
            }
        }
    }
}