package blocks;

import data.SolidBlock;

public class Glass extends SolidBlock {
    // Constructors
    public Glass() {
        super(
                "Glass",
                '□');
    }

    // Public Methods
    protected Glass getSelf() {
        return new Glass();
    }

    public Glass smelt() {
        return null;
    }
}
