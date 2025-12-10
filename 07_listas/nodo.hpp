/**
 * @file nodo.hpp
 * @brief Definición de la estructura Nodo para listas enlazadas
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#ifndef LISTAS_NODO_HPP
#define LISTAS_NODO_HPP

namespace std {
    /**
     * @struct Nodo
     * @brief Estructura que representa un nodo en una lista enlazada
     */
    struct Nodo{
        int dato;              ///< Dato almacenado en el nodo
        Nodo *siguiente;       ///< Puntero al siguiente nodo
        /**
         * @brief Constructor del nodo
         * @param a Valor a almacenar en el nodo
         */
        Nodo(int a);
        /**
         * @brief Imprime la información del nodo
         */
        void imprimir();
    };

} // std

#endif //LISTAS_NODO_HPP
