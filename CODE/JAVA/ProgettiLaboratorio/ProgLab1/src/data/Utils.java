package ProgettiLaboratorio.ProgLab1.src.data;

public class Utils {
    public static boolean checkCoords2Mat(int x, int y, int x_max, int y_max) {
        return x >= 0 && x < x_max && y >= 0 && y < y_max;
    }

    public static boolean checkCoords2Mat(int x, int y, int z, int x_max, int y_max, int z_max) {
        return x >= 0 && x < x_max && y >= 0 && y < y_max && z >= 0 && z < z_max;
    }

}
