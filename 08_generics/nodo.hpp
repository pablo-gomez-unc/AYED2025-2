/**
 * @file nodo.hpp
 * @brief Definición de la estructura Nodo genérica para listas enlazadas
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#ifndef LISTAS_NODO_HPP
#define LISTAS_NODO_HPP

/**
 * @struct Nodo
 * @brief Estructura genérica que representa un nodo en una lista enlazada
 * @tparam T Tipo de dato almacenado en el nodo
 */
template <typename T>
struct Nodo{
    T dato;              ///< Dato almacenado en el nodo
    Nodo<T> *siguiente;   ///< Puntero al siguiente nodo
    /**
     * @brief Constructor del nodo
     * @param a Valor a almacenar en el nodo
     */
    Nodo(T a);
    /**
     * @brief Imprime la información del nodo
     */
    void imprimir();
};

/**
 * @brief Constructor del nodo
 * @tparam T Tipo de dato
 * @param a Valor a almacenar en el nodo
 */
template<typename T>
Nodo<T>::Nodo(T a): dato(a), siguiente(nullptr) {}

/**
 * @brief Imprime la información del nodo
 * @tparam T Tipo de dato
 */
template<typename T>
void Nodo<T>::imprimir() {
    std::cout << "[NODO] valor: " << dato
              << " siguiente : "  << siguiente
              << std::endl;
}

#endif //LISTAS_NODO_HPP
