package Lecture_08;

public class Number {
    private int n;
    public Number(){
        this.n = 0;
    }
    public Number(int n) {
            this.n = n;
    }
    public int getInt() {
        return n;
    }
    void setInt(int n) {
        this.n = n;
    }
    //
    public String prettyprint(){
        return "[Num: "+this.n +"]";
    }
    public String toString(){
        return this.prettyprint()+" ID: "+super.toString();
    }
}
