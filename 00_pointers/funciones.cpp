/**
 * @file funciones.cpp
 * @brief Implementación de funciones para demostrar el uso de referencias, copias y punteros
 * @author Roberto Pablo Gomez
 * @date 13/03/2025
 */

#include <iostream>

/**
 * @brief Modifica un valor mediante puntero
 * @param a Puntero al entero que será modificado
 */
void funcValorPuntero(int* a) {
    *a = 20;
    std::cout << *a << std::endl;
}

/**
 * @brief Modifica un valor mediante referencia
 * @param a Referencia al entero que será modificado
 */
void funcValorRef(int& a) {
    a = 10;
    std::cout << a << std::endl;
}

/**
 * @brief Recibe un valor por copia (no modifica el original)
 * @param a Entero pasado por valor
 */
void funcValorCopia(int a) {
    a = 10;
    std::cout << a << std::endl;
}
