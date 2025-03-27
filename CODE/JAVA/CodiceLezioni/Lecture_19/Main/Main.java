package Lecture_19.Main;

import Lecture_19.controller.ClassroomController;
import Lecture_19.controller.StudentController;
import Lecture_19.model.Classroom;
import Lecture_19.model.Student;
import Lecture_19.view.MainView;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import java.util.ArrayList;

/*
MVC e` un design pattern molto usato
serve per separare la business logic dalla display logic
Q: cosa significano business logic e display logic?
A: https://edencoding.com/mvc-in-javafx/
acronimo:
M = model
V = view
C = controller
visualizzazione grafica: https://bovolato.dev/it/blog/tutorial-java/mvc/
il potere dell'MVC si vede specialmente quando andiamo ad estendere
un'applicazione.
qui facciamo proprio questa cosa, partiamo da una app semplice,
con requisiti di business logic semplice
per aggiungerne altri

per prima cosa: organizziamo i package
- nel package model, mettiamo la business logic iniziale:
    vogliamo poter visualizzare uno studente,
    la cui eta` e` fissa, e il nome si puo` cambiare con click utente
- nel package view, mettiamo la grafica dello studente:
    una hbox con un bottone per il nome , e un testo per l'eta`
- nel package controller, mettiamo lo studentcontroller
    il controller deve:
        1 prendere l'input utente
            -> quindi e` un handler, che leghiamo al bottone della view
        2 modificare il modello accordingly
            -> quindi deve avere una reference al model: student
        3 modificare la view accordingly
            -> quindi deve avere una reference alla view: studentview
    da qui deduciamo anche che:
        model e view non si parlano, quindi non hanno bisogno di
        references tra loro
        e neanche di references a controller, perche` non devono
        dire nulla al controller

ora possiamo runnare l'app e usarla.
Cominciamo con le estensioni:
    Q: se vogliamo cambiare il nome di uno studente con un tasto?
    A: per non duplicare codice,
        mettiamo il key handler dentro al controller

    Q: cambiamo il modello. non piu` un solo studente, ma una lista
        cioe` una classe.
    A: aggiungiamo classroom al modello:
            la classroom e` triviale,
            aggiungiamo poi la possibilita` di ringiovanire gli studenti
                questo si aggiunge al modello degli studenti
        aggiungiamo classroom view
            questo non e` triviale.
            la inizializziamo con un array di studentviews
        e classroomcontroller
            non e` necessario rendere i controller handlers
            se passiamo la reference del controller alla view,
            possiamo creare delle lambda che delegano ai metodi
            del controller
            questo permette per esempio di mettere handler diversi
            con lo stesso comportamento, in posti diversi

                Q: aggiungiamo l'ordinamento della classe, per nome ed eta`
                A: creiamo i comparators per gli studenti
                    e poi i comparators per i controller, che delegano ai
                    comparator per studenti

                    per fare l'update della view, dobbiamo linkare la mainview
                    al classroom controller e permetterne l'update
                        (metodo dentro MainView)

                    inoltre, vediamo che per fattorizzare il codice che usa
                    i comparators, definiamo una nostra interfaccia MyComparator
                    che oltre a comparare, permette di estrarre il comparator interno

            (per esempio, possiamo aggiungere un bottone alla
            mainview, che se cliccato ordina per nome)
         WARNING: in base a cosa e` selezionato, funzionano solo certi handlers
            per esempio gli shortcut S/N funzionano solo con la classroom
            (il bottone ringiovanisci) selezionato
            si potrebbero mettere tutti gli handler da tastiera in mainview ...
            e si fa. e` facilissimo.
            e la struttura col controller fa si che non dobbiamo fare
            altri grossi cambi
    il progetto attuale mostra 2 modi di gestire il controller:
    -1 controller che e` un handler (StudentController)
    -2 controller che gestisce la logica (ClassroomController)
    la soluzione 1 e` legata alla gestione GUI, se avessimo una
    Textual UI, allora dovremmo gestire con 2
 */
public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception{
        // primo modello
        Student s0 = new Student(54, "Pino");
        StudentController sc0 = new StudentController(s0);
        MainView mv = new MainView(sc0.getSv());

        // secondo modello
//        Student s1 = new Student(100, "Franco");
//        StudentController sc1 = new StudentController(s1);
//        Student s2 = new Student(1, "Zorro");
//        StudentController sc2 = new StudentController(s2);
//        // tutti gli studenti nella classroom
//        Classroom c = new Classroom();
//        c.add(s0); c.add(s1); c.add(s2);
//        //mi faccio la lista dei controller
//        ArrayList<StudentController> asc = new ArrayList<>();
//        asc.add(sc0); asc.add(sc1); asc.add(sc2);
//        // per passarla alla classroomcontroller
//        ClassroomController cc = new ClassroomController(c,asc);
//        // inizializzo la mainview
//        MainView mv = new MainView(cc);

        StackPane root = new StackPane(mv);
        primaryStage.setTitle("MVC Example");
        primaryStage.setScene(new Scene(root, 500, 400));
        primaryStage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}