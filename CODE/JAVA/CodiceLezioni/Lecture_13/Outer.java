package Lecture_13;

public class Outer {
    int attr = 1;
    Inner i = new Inner();

    public String m() {
        attr++;
        int local = 5;
        Object o = new Object() {
            public String toString() {
                attr++;
                // local = 6;
                return Integer.toString(local);
            }
        };
        return o.toString();
    }

    public String m2() {
        String s = null;
        if (true) {
            int local = 1;
            class Local {
                public String toString() {
                    attr++;
//                    return Integer.toString(local);
                    return "";
                }
            }
            local++;
            s = new Local().toString();
        }
        return s;
    }

    class Inner {
        int y = attr + 1;

        void m(int z) {
            attr += z;
            System.out.println("In inner class: x=" + attr + ", y=" + y);
        }
    }
}