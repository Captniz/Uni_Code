package Lecture_14.EsempioCalc;

import javafx.event.EventHandler;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;

public class KBFilter implements EventHandler<KeyEvent> {
    MiniCalculator2 mc = null;

    KBFilter(MiniCalculator2 mc) {
        this.mc = mc;
    }

    @Override
    public void handle(KeyEvent e) {
        String t = e.getCharacter();
        if ("1234567890".contains(t)) {
            return;
        } else if (t.equals(".")) {
            if (e.getTarget() instanceof TextField) {
                TextField tf = (TextField) (e.getTarget());
                System.out.println(tf.getText());
                if (tf.getText().contains(".")) {
                    e.consume();
                }
                return;
            }
        } else if ("+-/*".contains(t)) {
            mc.compute(t);
        }
        e.consume();
        return;
    }
}
