#include <iostream>

void incrementa(int x) {
    x=x+1;
}
void test_puntatori1(void) {
    int a=1;
    incrementa(a);
    std::cout << "a=" << a << std::endl;
    // MENTIMETER: quiz sul valore di a
}

//DRAW+SLIDE memory layout
void test_puntatori2() {
    int a,b,c,d;
    int * pa, * pb;
    pa=&a;
    pb=&b;
    a=1;
    b=2;
    c=a+b;
    d=*pa + *pb;
    std::cout << a << " " << b   << " " << c << std::endl;
    std::cout << a << " " << *pb << " " << d << std::endl;
}

// I tipi sono cambiati!
void incrementa_ptr(int *px) {
    *px=*px+1;
}
//DRAW+ slide memory layout
void test_puntatori3(void) {
    int a=1;
    incrementa_ptr(&a);
    std::cout << a << std::endl;
}