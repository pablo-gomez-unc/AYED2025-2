//
// Created by Roberto Pablo Gomez on 13/03/2025.
//
#include <iostream>

void funcValorPuntero(int* a) {
    *a = 20;
    std::cout << *a << std::endl;
}

void funcValorRef(int& a) {
    a = 10;
    std::cout << a << std::endl;
}

void funcValorCopia(int a) {
    a = 10;
    std::cout << a << std::endl;
}
