/**
 * @file main.cpp
 * @brief Programa principal que demuestra extensiones de listas enlazadas
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include "lista.hpp"

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    std::cout << "Extension Listas 2025" << std::endl;
    auto *l = new Lista<int>();
    l->agregar_inicio(1);
    l->agregar_inicio(2);
    l->agregar_inicio(3);
    l->agregar_inicio(4);
    l->agregar_final(0);
    l->imprimir();
    std::cout << "Tamaño: " << l->tamanio() << " Vacia: " << l->es_vacia() << std::endl;

    l->agregar_posicion(9,0);
    l->imprimir();

    l->eliminar(3);
    l->imprimir();

    l->eliminar(9);
    l->imprimir();

    l->eliminar_posicion(2);
    l->imprimir();
    delete l;
    return 0;
}
