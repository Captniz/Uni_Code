package ProgettiLaboratorio.ProgLab1.src.Main;

import java.util.Scanner;

import blocks.Sand;
import interfaces.Map;

public class Main {
    public static void main(String[] args) {
        std();
    }

    public static void std() {
        Map map = new Map(20, 5);
        Scanner scn = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            System.out.println();
            System.out.print("Enter row: ");
            int row = scn.nextInt();

            System.out.print("Enter column: ");
            int col = scn.nextInt();

            System.out.println("Changing: " + row + " - " + col);
            map.placeAtCoords(row, col, new blocks.Water());
            System.out.println();

            map.displayMap();
            System.out.println("\n-------------");
        }

        System.out.println(new Sand().smelt().getName());
        scn.close();
    }

    public static void test() {
    }
}
