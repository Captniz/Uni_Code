package data;
import interfaces.Map;

public abstract class GravBlock extends Block {
    // Constructors
    public GravBlock() {
        super();
    }

    public GravBlock(String name, char symbol) {
        super(
                name,
                symbol,
                true,
                false);
    }

    // Public Methods
    protected abstract Block getSelf();

    public abstract Block smelt();

    public void place(int x, int y, Map map) {
        if (!map.getBlock(x, y).isIntangible()) {
            return;
        }

        int i = y;
        Block block = getSelf();

        if (block.hasGravity() && y > 0) {
            for (i = y; i > 0; i--) {
                if (!map.getBlock(x, (i - 1)).isIntangible()) {
                    break;
                }
            }
        }

        map.setBlock(x, i, block);
    }
}
