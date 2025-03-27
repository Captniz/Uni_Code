#include <iostream>
// SLIDES per vettori

// Allocazione della memoria:
//  - statica (stack)
//  - diamica (heap)

void test_mem_static() {
    int a;
    std::cout << a << std::endl;
    // occhio all'inizializzazione delle variabili!
    a=3;
    std::cout << a << std::endl;
}

void test_mem_dyn() {
    int *pa;
    pa=new int;
    std::cout << *pa << std::endl;
    *pa=3;
    std::cout << *pa << std::endl;
    delete(pa);
    std::cout << *pa << std::endl;
}