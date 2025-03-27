package Lecture_07;

interface SomeInterface{
    int a();
}
// le enums possono implementare interfacce
public enum Orange implements SomeInterface { NAVEL, TEMPLE, BLOOD;
// back

    @Override
    public int a() {
        return 0;
    }
}