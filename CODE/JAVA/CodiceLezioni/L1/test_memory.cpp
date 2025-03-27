#include <iostream>
int fact(int n);
int somma(int a, int b);
int prodotto(int b, int a);

// nelle slides, questa e` chiamata 'main'
// DRAW + SLIDES: memory layout
void test_memory() {
    int a,b,res;
    std::cout << "dammi due numeri \n";
    std::cin >> a >> b;
    res=prodotto(a,b);
    std::cout << a << " * " << b << " = " << res << "\n";
}

int test_memory_rec(){
    //DRAW: qual e` il layout della memoria per questa funzione?
    int n;
    std::cout << "dammi un numero\n";
    std::cin >> n;
    std::cout << "Il suo fattoriale vale " << fact(n) << "\n";
    return 0;
}

int somma(int a, int b) {
    int res;
    res=a+b;
    return res;
}
int prodotto(int b, int a) {
    int res=0;
    for (int k=0; k<b; k++)
        res=somma(res,a);
    return res;
}

int fact(int n) {
    if (n==0) return 1;
    else return n*fact(n-1);
}