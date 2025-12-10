/**
 * @file main.cpp
 * @brief Programa principal que demuestra el uso de colas implementadas con arrays
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include "cola.hpp"

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {

    std::cout << "Colas 2025" << std::endl;
    auto* c = new Cola<int,5>();
    c->encolar(4);
    c->encolar(1);
    c->encolar(0);
    c->encolar(2);
    c->imprimir();

    int valor = c->desencolar();
    std::cout << "Desencolado - Nodo con valor: " << valor << " tamaño: " << c->get_tamanio() << std::endl;
    c->imprimir();

    valor = c->desencolar();
    std::cout << "Desencolado - Nodo con valor: " << valor << " tamaño: " << c->get_tamanio() << std::endl;
    c->imprimir();

    valor = c->desencolar();
    std::cout << "Desencolado - Nodo con valor: " << valor << " tamaño: " << c->get_tamanio() << std::endl;
    c->imprimir();

    valor = c->desencolar();
    std::cout << "Desencolado - Nodo con valor: " << valor << " tamaño: " << c->get_tamanio() << std::endl;
    c->imprimir();

    delete c;
    return 0;
}
