import data.Attributes;

public class Gerardo {
    private Attributes attributes;

    Gerardo() {
        attributes = new Attributes();
    }

    public void printAttributes() {
        System.out.println(attributes.toString());
    }

    public Attributes getAttributes() {
        return attributes;
    }
}