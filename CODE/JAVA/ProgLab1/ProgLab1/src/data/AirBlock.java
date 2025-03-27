package data;

import interfaces.Map;

public abstract class AirBlock extends Block {
    // Constructors
    public AirBlock() {
        super();
    }

    public AirBlock(String name, char symbol) {
        super(
                name,
                symbol,
                false,
                true);
    }

    // Public Methods
    protected abstract Block getSelf();

    public void place(int x, int y, Map map) {
        map.setBlock(x, y, getSelf());
    }
}
