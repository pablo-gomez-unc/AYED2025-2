/**
 * @file nodo.hpp
 * @brief Definición de la estructura Nodo genérica para colas y pilas
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#ifndef LISTAS_NODO_HPP
#define LISTAS_NODO_HPP

/**
 * @struct Nodo
 * @brief Estructura genérica que representa un nodo
 * @tparam T Tipo de dato almacenado en el nodo
 */
template <typename T>
struct Nodo{
    T dato;              ///< Dato almacenado en el nodo
    Nodo<T> *siguiente;  ///< Puntero al siguiente nodo
    /**
     * @brief Constructor del nodo
     * @param a Valor a almacenar en el nodo
     */
    Nodo(T a);
};

/**
 * @brief Constructor del nodo
 * @tparam T Tipo de dato
 * @param a Valor a almacenar en el nodo
 */
template<typename T>
Nodo<T>::Nodo(T a): dato(a), siguiente(nullptr) {}

#endif //LISTAS_NODO_HPP
