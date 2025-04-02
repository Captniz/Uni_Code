import data.*;
import mutations.*;

public class Main {
    public static void main(String[] args) {
        Gerardo gerardo = new Gerardo();

        Attributes attributes = gerardo.getAttributes();
        attributes.addMutation(new Fire());
        attributes.addMutation(new Strength());
        attributes.addMutation(new Speed());
        attributes.addMutation(new Tollerance());
        
        gerardo.printAttributes();

        System.out.println("------------------");

        attributes.removeMutation("Fire");
        attributes.removeMutation("Strength");
        attributes.removeMutation("Speed");
        attributes.removeMutation("Tollerance");

        gerardo.printAttributes();
    }
}
