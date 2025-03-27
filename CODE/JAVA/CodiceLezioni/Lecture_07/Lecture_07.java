package Lecture_07;

import Lecture_03.Persona;
import Lecture_04.Automobile;
import Lecture_05.Studente;

import java.util.function.Function;

public class Lecture_07 {
    public static void main(String[] args){
        // SLIDE: cast a volonta`
        Pila p = new Pila(10);
        // MENTIMETER: posso fare queste due righe?
//        p.inserisci("5");
//        Integer x = (Integer) p.estrai();

        // Semantics, to the rescue
        pila_gen();

        // SLIDE: generics in JAva
        // SLIDE: tipi generici

        // vediamo un esempio semplice
        test_pair();

        // vediamo un esempio che chiarifica alcuni benefici dei generici
        test_insieme();


        //SLIDE: generics e sottotipi
        // se   B <: A non e` vero che G<B>  <: G<A>
        Persona s = new Studente("asd"); //ok
        Persona[] ss = new Studente[100]; //ok
//        Pila<Persona> g = new Pila<Studente>(10);
        //SLIDE perche` : type erasure

        esempio_pairs();

        // posso avere una struttura dati generica e polimorfa?
        //  vorrei definire il tipo statico polimorfo, e per questo uso le wildcards

        Pila<?> pp = new Pila<Studente>(10);
        //SLIDE: wildcards

        // wildcard : utile per il re-assignment
        pp = new Pila<Object>(10);
        pp = new Pila<Automobile>(19);

        // ==== start
        // Subtyping con Wildcards
        // G<B> <: G<?>

        // MENTIMETER: posso fare:
//        pp.inserisci(new Automobile());//("pino"));

        // le wildcard sono piu` utili a livello di parametro di metodi
        //SLIDE esempio (modificato su pila)
        Pila<Persona> sp = new Pila<Persona>(10);
        sp.inserisci(new Persona("piero"));
        // guardiamo il metodo stampaPila in fondo a Pila (lec07)
        // MENTIMETER: perche` non va la riga sotto?
//        Pila.stampaPila(sp);
        // questa andra?
        Pila.stampaPila((Pila<Object>)((Object)sp));
        // questa andra?
//        Pila.stampaPila2(sp);
        // e questa ?
        sp.stampaPila2(sp);
        Object o = (Object) sp;
        // SLIDE bounded types (bounded parametric polymorphism)
        Pila<? extends Persona> g = new Pila<Studente>(10);
        // non posso metterci dentro Gatti
        // funziona anche con le interfacce?
        Pila<? extends Volatile> gg = new Pila<Rondine>(10);

        // MENTIMETER // compilano?
        Pila<? super Rondine> ssp;
        ssp = new Pila<Rondine>(10);
        ssp = new Pila<Volatile>(10);
//        ssp = new Pila<RondineTurbo>(10);
        // SLIDE bounds e super
        // SLIDE: una pila generica
        //      non possiamo perche` con la type erasure diventa tutto object,
        //      e quindi perderemmo le type info
        //      ma quindi? non usiamo array ma liste / tipi definiti nei generics
        // SLIDE limitazioni: costruttore di array (2x)
        //      type erasure ci impedisce di usare instanceof

        // vediamo un esempio di utilizzo del bounded polymorphism
        pila_esempio();

        // BONUS! Parametricity
        //  parametric polymorphism gives PARAMETRICITY
        //  - a very important property to be able to reason about types and code.
        //  - a polymorphic program has parametricity if it applies
        //      a uniform algorithm independently of
        //      the type instantiations at which it is applied
        //  - Parametricity guarantees that polymorphic functions
        //      cannot behave differently when invoked at different types.
        // un bonus aggiunto della parametricity e`:
        //  Representation Independence: ensuring that the use of an abstract type
        //     (generic, parametric, etc) is independent of its representation.
        //     Changes in the representation (or different
        //     instantiations of a type argument) should
        //     have no effect on the code outside the type.

        // type reasoning
        // Cosa sappiamo del comportamento di questo metodo:
            //  public boolean test();
        // Dobbiamo vederne l'implementazione?
        // Come lo sappiamo?
        // E di questi metodi?
            //  1) public <A> List<A> meth(List<A> l);
            //  2) private <A,B> B test(A a)
        //  free theorems:
        //      From the type of a polymorphic function we can
        //      derive a theorem that it satisfies.
        //      Every function of the same type satisfies the same theorem.

        //Theorem for 1
        //Every element A in the result list appears in the input.
        //Contraposed, If A is not in the input, it is not in the result

        // type of int constants: \forall \alpha . \alpha -> Int
        // public <A> int test(A a)
        // type of uninhabited functions \forall \alpha . () -> \alpha
        // type of identity \forall \alpha . \alpha \to \alpha
        // public <A> A test(A a)
        // type of boolean choice \forall \alpha . \alpha \to \alpha \to \alpha

        // se ho ulteriori informazioni sul comportamento
        // specifico di alcune funzioni
        // tipo map, posso fare ottimizzazioni di codice!
        Pila<Integer> pi = new Pila<Integer>(5);
        for (int k = 0 ; k<5 ; k++){
            pi.inserisci(k);
        }
        Function<Integer, Double> timespi = (e) -> {
            return e * Math.PI;
        };
        Double dv = pi.map(timespi).estrai();
        Double dd = timespi.apply(pi.estrai()) ;
        // sono diversi o uguali?

        // cosa rompe la parametricity ?


        // TODO: Mockup V/F online per domani
        // fine: goto 8
    }


    private <A extends B,B> B test(A a){
        return null;
    }

    private static void pila_gen(){
        // SLIDE: generics
        // qui vediamo il primo cambiamento:
        //      c'e` un parametro ulteriore (parametro di tipo),
        //      tra parentesi angolari
        // prima di vedere cosa cambia in Pila:
        //  guardiamo Test di sotto
        // poi andiamo dentro a Pila
        Pila<Integer> p = new Pila<Integer>(10);
        // quando "usiamo" la pila generica,
        // dobbiamo instanziare il parametro di tipo
        //  cosi` come chiamiamo "successore(10),
        //  dobbiamo dire che tipo di pila stiamo creando

        // MENTIMETER: possiamo inserire una String in una pila in Integer?
//         p.inserisci("5");
        // un int si inserisce grazie all'autoboxing
        p.inserisci(10);
        Integer x = (Integer) p.estrai();
    }

    // coi generici abbiamo un nuovo tipo di parametro: parametro di tipo
    // Parallelo: le funzioni definiscono dei parametri,
    //      che vengono sostituiti dai valori quando la funzione viene chiamata
    // MENTIMETER: come si chiamano qui?
    class Test{
        private static int successore(int x){
            return x+1;
        }
        public static void test(){
            successore(10);
        }
    }
    // back

    private static void test_pair(){
        // SLIDE esempio
        // vediamo la definizione di Pair
        Pair<String,Double> p = new Pair<String,Double>("PI", 3.14);
        // alcuni parametri possono essere inferiti
        // molte altre cose potrebbero essere inferite,
        // ma lo vedremo con chi fara` Rust, che e` un linguaggio moderno
        Pair<String,Double> pp = new Pair<>("PI", 3.14);
    }
    // back

    private static void test_insieme(){
        //SLIDE
        // se facciamo una Pila (lec 06)
        Lecture_06.Pila p6 = new Lecture_06.Pila(10);
        p6.inserisci(7);
        p6.inserisci("what");
        // ci mettiamo dentro Int, Float, e cose diverse
        // con una Pila (lec 07) non possiamo
        Pila<Integer> p7 = new Pila(10);
        p7.inserisci(6);
//        p7.inserisci("what");
        // back
    }

    private static void esempio_pairs() {
        // SLIDE: esempio (modificato)
        Pair<String, Double> pair2 = gimmeGenPair();
        String s2 = pair2.getFirst();
        Double d2 = pair2.getSecond();
        Object o2 = pair2.getSecond();
//        pair2 = new Pair<>(3.14 , "asd");

        // un oggetto di tipo PairO e` quello che viene generato dalla type erasure
        PairO pair = gimmePair();
        String s = (String) pair.getFirst();
        Double d = (Double) pair.getSecond();
        Object o = pair.getSecond();
        pair = new PairO(3.14, "asd");

        //back
    }

    private static PairO gimmePair(){
        return new PairO("PI", 3.14);
    }
    private static Pair<String,Double> gimmeGenPair(){
        return new Pair<>("PI", 3.14);
    }

    private static void pila_esempio(){
        // usiamo i bounds delle bounded wildcard per avere piu` informazioni su cosa fare
        //  tipi -> cosa facciamo con quegli oggetti
        // SLIDE: esempio
        // guardiamo il metodo svuotaAggrega di Pila
        Pila<Integer> pi = new Pila<Integer>(10); // [0,1,2,3]
        pi.inserisci(0);pi.inserisci(1);pi.inserisci(2);pi.inserisci(3);
        Pila<Double> pd = new Pila<Double>(10); // [0.0,1.1,2.2,3.3]
        pd.inserisci(0.0);pd.inserisci(1.1);pd.inserisci(2.2);pd.inserisci(3.3);
        System.out.println(Pila.svuotaAggrega(pi));
        System.out.println(Pila.svuotaAggrega(pd));
        Pila<String> ps = new Pila<String>(10); // ["0","1","2","3"];
        ps.inserisci("0");ps.inserisci("1");ps.inserisci("2");ps.inserisci("3");
        // MENTIMETER: funziona?
//        System.out.println(Pila.svuotaAggrega(ps));
//        System.out.println(Pila.svuotaAggrega((Pila<Number>)(Object)ps));
    }
    // back


}

class Rondine implements Volatile{
    public void vola(){}
}
class RondineTurbo extends Rondine{

}
