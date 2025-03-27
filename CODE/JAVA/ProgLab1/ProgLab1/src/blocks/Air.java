package blocks;

import data.AirBlock;

public class Air extends AirBlock {
    // Constructors
    public Air() {
        super("Air", ' ');
    }

    // Public Methods
    protected Air getSelf() {
        return new Air();
    }
}
