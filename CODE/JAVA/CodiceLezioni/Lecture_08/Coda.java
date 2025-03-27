package Lecture_08;

public class Coda extends ArrayDati {
    public int estrai() {
        Number x = null;
        if (this.size()==0){
            System.out.println("Tentativo di estrarre da una Coda vuota");
            //System.exit(1); //commented or things break
            return -1;
        }
        //MENTIMETER: c'e` bisogno del cast?
        x = (Number) this.remove(0);
        //  typo in slides, must pop from index 0, not 1
        return x.getInt();
    }
}