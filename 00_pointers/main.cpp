#include <iostream>
#include "funciones.hpp"

int main() {
    int *ptr = nullptr;
    int a = 10;

    ptr = &a;
    std::cout << "Direccion:" << ptr << " Valor: " <<  *ptr << std::endl ;

    *ptr = 20;
    std::cout << "a: " << a << " *ptr: " <<  *ptr << std::endl ;

    int *ptr2 = new int;
    std::cout << "*ptr2: " <<  *ptr2 << std::endl ;
    *ptr2 = 22;
    std::cout << "*ptr2: " <<  *ptr2 << std::endl ;
    delete ptr2;

    double x = 5.5;
    double y = 10.2;
    double z;
    double *px = &x;
    double& ry = y;
    *px = 3.14;
    z = ry;
    double &r = *px;
    r = 99.44;
    px = &z;
    ry = *px;

    char miString[9] = {'a','c', 'b','d','e','f','g','h','i'};
    for (int i = 0; i < 9; i++) {
        std::cout << miString[i] ;
    }
    std::cout << std::endl;

    int miArray[5] = {1,11,3,4,5};
    std::cout << miArray << std::endl;
    std::cout << *miArray << std::endl;
    std::cout << miArray[0] << std::endl;
    std::cout << *(miArray+3) << std::endl;
    std::cout << &miArray << std::endl;
    std::cout << &miArray+1 << std::endl;

    int miArray2[5] = {1,11,3,4,5};
    std::cout << miArray2 << std::endl;

    int valor = 10;
    funcValorCopia(valor);

    int referencia = 10;
    funcValorRef(referencia);

    return 0;
}