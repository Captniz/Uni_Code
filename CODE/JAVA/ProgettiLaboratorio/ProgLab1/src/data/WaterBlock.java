package ProgettiLaboratorio.ProgLab1.src.data;

import interfaces.Map;

public abstract class WaterBlock extends Block {
    // Constructors
    public WaterBlock() {
        super();
    }

    public WaterBlock(String name, char symbol) {
        super(
                name,
                symbol,
                true,
                true);
    }

    // Public Methods
    protected abstract Block getSelf();

    public void place(int x, int y, Map map) {
        if (!map.getBlock(x, y).isIntangible()) {
            return;
        }

        int i = y;
        Block block = getSelf();

        if (block.hasGravity() && y > 0) {
            for (i = y; i > 0; i--) {
                map.setBlock(x, i, block);
                if (!map.getBlock(x, (i - 1)).isIntangible()) {
                    break;
                }
            }
        }

        map.setBlock(x, i, block);

        int newy = i;
        i = x;
        if (x > 0) {
            for (i = x; i > 0; i--) {
                map.setBlock(i, newy, block);
                if (!map.getBlock((i - 1), y).isIntangible()) {
                    break;
                }
            }
        }
        map.setBlock(i, newy, block);

        i = x;
        if (x < map.getWidth() - 1) {
            for (i = x; i < map.getWidth() - 1; i++) {
                map.setBlock(i, newy, block);
                if (!map.getBlock((i + 1), y).isIntangible()) {
                    break;
                }
            }
        }
        map.setBlock(i, newy, block);
    }
}
