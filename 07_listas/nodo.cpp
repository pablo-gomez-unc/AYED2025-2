/**
 * @file nodo.cpp
 * @brief Implementación de la estructura Nodo
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#include "nodo.hpp"
#include <iostream>

namespace std {

/**
 * @brief Constructor del nodo
 * @param a Valor a almacenar en el nodo
 */
Nodo::Nodo(int a): dato(a), siguiente(nullptr){}

/**
 * @brief Imprime la información del nodo
 */
void Nodo::imprimir() {
    std::cout << "[NODO] valor: " << dato
              << " siguiente : "  << siguiente
              << std::endl;
}

} // std