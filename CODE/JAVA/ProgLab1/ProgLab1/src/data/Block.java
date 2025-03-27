package data;
import interfaces.Map;

public abstract class Block {
    protected String name;
    protected char symbol;
    protected boolean has_gravity;
    protected boolean is_intangible;

    // Constructors
    public Block() {
        this.name = "block";
        this.symbol = 'X';
        this.has_gravity = false;
        this.is_intangible = false;
    }

    protected Block(String name, char symbol, boolean has_gravity, boolean is_intangible) {
        this.name = name;
        this.symbol = symbol;
        this.has_gravity = has_gravity;
        this.is_intangible = is_intangible;
    }

    // Private/protected Methods
    protected abstract Block getSelf();

    // Public Methods
    public void display() {
        System.out.print(symbol);
    }

    public String getName() {
        return name;
    }

    public char getSymbol() {
        return symbol;
    }

    public boolean hasGravity() {
        return has_gravity;
    }

    public boolean isIntangible() {
        return is_intangible;
    }
    public abstract void place(int x, int y, Map map);
}
