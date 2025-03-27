package blocks;

import data.Block;
import data.GravBlock;

public class Sand extends GravBlock {
    // Constructors
    public Sand() {
        super("Sand", '░');
    }

    // Public Methods
    protected Sand getSelf() {
        return new Sand();
    }

    public Block smelt(String className) {
        //return an instance of the class that is passed in
        try {
            return (Block) Class.forName("blocks." + className).getConstructor().newInstance();
        } catch (Exception e) {
            return null;
        }
        
        //return new Glass();
    }
}
