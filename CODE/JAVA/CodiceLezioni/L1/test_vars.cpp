#include <iostream>
// una variabile globale
int a=5;
void f() {
    // a cosa si riferisce la lina di sotto?
    a=a+1;
    std::cout << "a in f " << a << std::endl;
    return;
}

void test_vars() {
    std::cout << "a in main " << a << std::endl;
    f();
    std::cout << "a in main " << a << std::endl;
    // DRAW: memory layout
}

void g() {
    // due variabili locali
    int a=2, b=4;
    printf("(a,b) in g: (%d,%d) -",a,b);
    return;
}
void test_vars2() {
    // a cosa si riferisce la linea di sott?
    a = 5;
    // una variabile locale
    int b=6;
    printf("(a,b) in main: (%d,%d) -",a,b);
    g();
    printf("(a,b) in main: (%d,%d)\n",a,b);
    // DRAW: memory layout
}

// MENTIMETER: quiz sul valore di s1
void modifica1(int s1) {
    s1++;;
}
void test_s1(void) {
    int s1=1;
    modifica1(s1);
    std::cout << "s1=" << s1 << std::endl;
}
// MENTIMETER: quiz sul valore di s2
int s2;
void modifica2() {
    s2++;
}
void test_s2(void) {
    s2=1;
    modifica2();
    std::cout << "s2=" << s2 << std::endl;
}