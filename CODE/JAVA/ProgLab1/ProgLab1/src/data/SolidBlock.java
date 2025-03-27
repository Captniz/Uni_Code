package data;
import interfaces.Map;

public abstract class SolidBlock extends Block {
    // Constructors
    protected SolidBlock() {
        super();
    }

    protected SolidBlock(String name, char symbol) {
        super(
                name,
                symbol,
                false,
                false);
    }

    // Public Methods
    protected abstract Block getSelf();

    public abstract Block smelt();

    public void place(int x, int y, Map map) {
        if (!map.getBlock(x, y).isIntangible()) {
            return;
        }
        map.setBlock(x, y, getSelf());
    }
}
