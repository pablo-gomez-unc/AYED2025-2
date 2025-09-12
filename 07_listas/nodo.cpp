//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#include "nodo.hpp"
#include <iostream>

namespace std {

Nodo::Nodo(int a): dato(a), siguiente(nullptr){}

void Nodo::imprimir() {
    std::cout << "[NODO] valor: " << dato
              << " siguiente : "  << siguiente
              << std::endl;
}

} // std