package Lecture_08;

class Pila extends ArrayDati {
    public int estrai() {
        Number x = null;
        if (this.size() == 0) {
            System.out.println("Tentativo di estrarre da una Pila vuota");
            // System.exit(1); //commented or things break
            return -1;
        }
        //TODO: only difference is the argument of remove
        x = (Number)(this.remove(this.size()-1));
        //FIXME: typo in slides, must pop from size-1
        return x.getInt();
    }
}