public interface TestClass {
    public void test();

    public void test2();

    public default void test3() {
        System.out.println("Hello World");
    }
}