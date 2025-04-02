package ProgettiLaboratorio.ProgLab1.src.blocks;

import data.SolidBlock;

public class Stone extends SolidBlock {
    // Constructors
    public Stone() {
        super(
                "Stone",
                '█');
    }

    // Public Methods
    protected Stone getSelf() {
        return new Stone();
    }

    public Stone smelt() {
        return null;
    }
}
