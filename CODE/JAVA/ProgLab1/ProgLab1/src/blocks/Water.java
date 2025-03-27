package blocks;

import data.WaterBlock;

public class Water extends WaterBlock {
    // Constructors
    public Water() {
        super("Water", '⢕');
    }

    // Public Methods
    protected Water getSelf() {
        return new Water();
    }    
}
