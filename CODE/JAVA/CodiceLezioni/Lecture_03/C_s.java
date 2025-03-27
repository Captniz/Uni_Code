package Lecture_03;

public class C_s {
    private static int total = 0;
    private static final int aa=0;
    private final int aaa;
    // campo int static
    // non dobbiamo per forza inizializzare questi valori
    public static int x_static_int;
    // campo int non static
    public int y_nonstatic_int;
    // campo static di tipo Persona, e` un Oggetto
    // se non inizializziamo, che valore avra`?
    // come 'arrp' di qualche minuto fa ...
    // questo invece viene inizializzato ad un valore preciso
    public static Persona a_static_Obj_field = new Persona("Statico");

    public C_s(){
        aaa=0;
        total++;
    }
    // metodo static
    public static int a_static_method(Persona p){
        return p.eta;
    }
    // metodo non static
    public int get_sum(){
        return this.y_nonstatic_int + C_s.x_static_int;
    }
}
// back to main
