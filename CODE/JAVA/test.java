public class test {
    public static void main(String[] args) {
        int ctr = 0;
        for (;;) {
            System.out.print((char) (ctr % 26 + 65));
            ctr++;
        }
    }
}