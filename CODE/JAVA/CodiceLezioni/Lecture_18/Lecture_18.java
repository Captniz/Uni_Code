package Lecture_18;

import Lecture_08.Coda;
import Lecture_18.esempio.Duck;
import Lecture_18.esempio.flyable.CannoFly;
import Lecture_18.esempio.quackable.Squeak;

import java.util.List;

public class Lecture_18 {

    public static void main(String[] args){
        // Composition VS Inheritance

        // Problema: riutilizzo delle funzionalita`

        // Soluzione 1: ereditarieta`
        // white-box reusing: white-box perche` vediamo lo stato interno delle superclassi
        //  quando? -> quando la relazione e` chiaramente una is-a (chiaramente == ? eh...)
        //          -> quando abbiamo multiple inheritance ( C++ ) ma occhio al diamond problem!

        // benefici: gestione univoca dello stato
        //  piu` facile da rappresentare in memoria,
        //  piu` centralizzata la logica di stato

        // per esempio Coda etc. di Lecture_08
        //  non aggiungendo logica strana, riutilizziamo molte delle API
        Coda c = new Coda();
        // un buon esempio questo?
        // no. non riutilizziamo nulla di quello che ereditiamo, e non ha senso farlo
        // un utente puo` usare una Coda con .remove, che non vogliamo.

        // un buon esempio, VettoreDati e Pila di Lecture_06
        //  tutto cio` che ereditiamo da VettoreDati si usa in Pila

        // hint -> spesso vogliamo una classe astratta, con un livello di classi concrete sotto
        //  se abbiamo molti livelli di nested classi e` strano.
        //  TODO: find the source where i read this

        // Problemi: troppi comportamenti possibili sulla sottoclasse

        // Problemi con l'ereditarieta`:
        //  violazione di encapsulation
        //  a volte non sappiamo cosa andiamo ad ereditare
        //  -> overriding puo` causare comportamenti erronei

        InstrumentedHashSet<String> s = new InstrumentedHashSet<String>(1,2);
        s.addAll(List.of("Snap", "Crackle", "Pop"));
        //MENTIMETER: cosa viene stampato? 0/3/6
        System.out.println(s.getAddCount());

        // Soluzione 2: composizione
        // black-box reusing: non vediamo lo stato delle superclassi
        // in Java abbiamo Object-level composition
        // vediamo il diagramma: https://en.wikipedia.org/wiki/Composition_over_inheritance#/media/File:UML_diagram_of_composition_over_inheritance.svg

        // implementiamo questo codice: Duck, le varie interfacce
        //  object-level composition: il parent object (Duck) ha dei subobject privati su cui fa forward

        Duck d = new Duck();
        d.setFlybehaviour(new CannoFly());
        d.setQuackbehaviour(new Squeak());
        d.display();
        // capiamo l'impatto sul design partendo da:
        //  cos'e` una classe, e capendo come i design
        //  toccano gli aspetti di una classe

        // reuse? si, cio` che puo` volare ha un campo Flyable
        // e riusiamo gli stessi oggetti

        // e lo stato? se aggiungiamo la flying speed,
        // dobbiamo avere un metodo .getSpeed, e quel campo finisce in un altro
        //  oggetto e ne dobbiamo esporre il getter, che diventa visibile a tutti

        // Problemi: forwarding methods, set up dei subobjects
        //  c'e` addirittura una proposal di una tag @Delegate

        // Lab -> si puo` fare piu` composition-based
        //  io l'ho fatto piu` inheritance based
        //  ma ogni Block potrebbe delegare cose come
        //      pickable / falls_with_gravity / falls_through a subobject
        //  visto che altri blocchi / entita` possono riutilizzare il codice
        //  di queste funzionalita` (tipo, altre entities che non sono blocchi)

        // in altri linguaggi abbiamo Type-level composition
        //      -> Traits
        //  in Java un pochino tramite default implementations in interfaces
        //  MA non dobbiamo avere sub-objects, definiamo il trait per ogni tipo,
        //  e poi estendiamo il comportamento del tipo con quello che dice il trait

        // -> non abbiamo il problema del forwarding!
        // -> i traits devono venire supportati dal linguaggio pero`

    }

    /* References
    [1] https://cdn-uploads.piazza.com/paste/lf9k3jtpw576l8/86a4bc368ed030689ce72cb235ac2363a8f721335b6070368a9036d68ae31161/Design-Patterns-Introduction.pdf
        pagine 18-19-20
    [2] https://en.wikipedia.org/wiki/Composition_over_inheritance#/media/File:UML_diagram_of_composition_over_inheritance.svg
    [3] https://en.wikipedia.org/wiki/Composition_over_inheritance
        -> non proprio adeguata, visto l'uso di C++
     */
}
