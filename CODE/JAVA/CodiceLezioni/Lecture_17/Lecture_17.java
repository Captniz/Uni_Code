package Lecture_17;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.layout.Pane;

import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.function.ToIntFunction;

public class Lecture_17 {
    public static void main(String[] args){
        // lambdas
        //  cosa e` una lambda?
        //  - teoria: una funzione ANONIMA
        //      https://en.wikipedia.org/wiki/Anonymous_function
        //    - anonima? -> non la invochiamo tramite il suo nome,
        //      ma in costrutti appositi dove il nome non serve o dove e` implicito
        //  esempio canonico: la map, la filter
        //      list.map(\lambda x. x.toString());
        //      list.filter(\lambda x. x.isOdd());
        //    non mi serve il nome delle 2 lambda qui: vengono usate qui e mai piu`
        //  dopo vediamo come si fanno in Java
        //  - implementazione: una closure
        //    chiusura: coppia codice-environment con i bindings per risolvere
        //    le variabili CATTURATE dal codice
        //    - cattura in java? ->
        //      variabili locali che siano effectively final
        //      variabili di istanza

        Pane p = new Pane();
        // non e` una lambda questa, e` un oggetto di una anonymous class
        p.addEventHandler(ActionEvent.ANY, new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {

            }
        });
        // questa e` una lambda
        p.addEventHandler(ActionEvent.ANY, event -> {});
        // sintassi: PARAM(s) FRECCIA BODY
        // Perche` funziona?
        //  https://docs.oracle.com/javase/8/javafx/api/javafx/event/EventHandler.html
        //  controlliamo EventHandler -> ha un solo metodo!
        //  https://docs.oracle.com/javase/8/docs/api/java/lang/FunctionalInterface.html

        // lambda per il mouseevent -> se eventhandler avesse 2 metodi?
        MyClassFI mfi = new MyClassFI();
        MyClassNotFI mnf = new MyClassNotFI();
        MyConsumer mc = new MyConsumer();
        // ovviamente funziona
        mc.consumeFI(mfi);
        // perche` funziona questo?
        mc.consumeFI( () -> {return "What";} );
        // ovviamente funziona
        mc.consumeNotFI(mnf);
        // ovviamente non funziona: non sa cosa chiamare!
        // mc.consumeNotFI(()->{return 2;});

        // I mouse events, pero` non ci dicono tutta la storia delle lambda
        ArrayList<Integer> a = new ArrayList<>(10);
        //  guardiamo il tipo del primo metodo (forEach):
        // https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html
        a.forEach((i) -> {i.hashCode();});            // consumer
        // MENTIMETER: qual e` il tipo di i?
        // cos'e` Consumer? membro di
        //  https://docs.oracle.com/javase/8/docs/api/java/util/function/package-summary.html
        // ci sono diverse interfacce che forzano il tipo delle funzioni anonime
        //  che possono venire implementate
        //  Consumer per esempio e` un T -> void, cioe` consuma cio` che gli vien dato

        a.stream().filter((i) -> {return i.intValue()>0;});    // predicate
        //  https://docs.oracle.com/javase/8/docs/api/java/util/function/Predicate.html
        // la javadoc ci dice quale e` il metodo funzionale qui

        ToIntFunction tif = new ToIntFunction() {
            @Override
            public int applyAsInt(Object value) {
                return 0;
            }
        };
        a.stream().mapToInt(tif);  // tointfunction
        // non dobbiamo per forza passare lambdas, ma vanno bene anche oggetti
        //  che abbiano il tipo corretto

        // Q : quale e` il tipo piu` generale per una funzione 'f'?

        // due references utili:
        //  https://docs.oracle.com/javase/8/docs/api/java/util/function/Function.html
        // l'interfaccia piu` generica: prendo una cosa e ne ritorno un'altra

        //  http://www.java2s.com/Tutorials/Java/java.util.function/Function/index.htm
        // una buona lista dei contenuti del package

        // Implementativamente pero`?
        //  Classi e funzioni anonime sono 2 cose DIVERSE a livello di bytecode
        // anon class -> each in 1 file
        //      code in code cache
        // lambdas are not translated into anon classes
        //  they are translated to things that get called at runtime
        //  via the invokedynamic bytecode instruction
        // More infos:
        // https://www.infoq.com/articles/Java-8-Lambdas-A-Peek-Under-the-Hood/

        // cose utili (7!!!) e meno utili (8 -> marea di ...)
        //  https://www.baeldung.com/java-8-lambda-expressions-tips

        // THIS funziona diversamente tra anonymous classes e lambdas

        // clone -> open Test


    }
}
