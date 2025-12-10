/**
 * @file funciones.hpp
 * @brief Funciones de ejemplo para demostrar el uso de referencias, copias y punteros
 * @author Roberto Pablo Gomez
 * @date 07/08/2025
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

/**
 * @brief Modifica un valor mediante referencia
 * @param a Referencia al entero que será modificado
 */
void funcValorRef(int& a);

/**
 * @brief Recibe un valor por copia (no modifica el original)
 * @param a Entero pasado por valor
 */
void funcValorCopia(int a);

/**
 * @brief Modifica un valor mediante puntero
 * @param a Puntero al entero que será modificado
 */
void funcValorPuntero(int* a);


#endif //FUNCIONES_HPP
