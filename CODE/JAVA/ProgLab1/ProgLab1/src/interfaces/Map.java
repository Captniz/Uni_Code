package interfaces;

import blocks.*;
import data.*;

public class Map {
    // Fields
    private int height;
    private int width;
    private Block[][] map;

    // Constructors
    public Map(int width, int height) {
        map = new Block[height][width];
        this.width = width;
        this.height = height;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                map[i][j] = new Air();
            }
        }
    }

    // Private Methods

    private void swapBlocks(int x1, int y1, int x2, int y2) {
        Block temp = map[y1][x1];
        map[y1][x1] = map[y2][x2];
        map[y2][x2] = temp;
    }

    // Public Methods
    public void displayMap() {
        System.out.print('┌');
        for (int i = 0; i < width; i++) {
            System.out.print('─');
        }
        System.out.println('┐');

        for (int i = (height - 1); i >= 0; i--) {
            System.out.print('│');
            for (int j = 0; j < width; j++) {
                map[i][j].display();
            }
            System.out.println('│');
        }

        System.out.print('└');
        for (int i = 0; i < width; i++) {
            System.out.print('█');
        }
        System.out.println('┘');
    }

    public void placeAtCoords(int x, int y, Block block) {
        block.place(x, y, this);
    }

    public Block getBlock(int x, int y) {
        return map[y][x];
    }

    public void setBlock(int x, int y, Block block) {
        map[y][x] = block;
    }

    public int getHeight() {
        return height;
    }

    public int getWidth() {
        return width;
    }
}
