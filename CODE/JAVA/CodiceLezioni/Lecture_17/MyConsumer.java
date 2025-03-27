package Lecture_17;

public class MyConsumer {
    public void consumeFI(MYFI m){
        m.singlemethod();
    }
    public void consumeNotFI(MYNotFI m){
        if (Math.random() > 0.5){
            m.m1();
        }else{
            m.m2();
        }
    }
}
