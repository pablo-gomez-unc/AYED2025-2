/**
 * @file lista.hpp
 * @brief Definición de la clase Lista (lista enlazada)
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#ifndef LISTAS_LISTA_HPP
#define LISTAS_LISTA_HPP

#include "nodo.hpp"

/**
 * @class Lista
 * @brief Clase que representa una lista enlazada
 */
class Lista {
public:
    /**
     * @brief Constructor por defecto (lista vacía)
     */
    Lista ();
    /**
     * @brief Constructor que inicializa la lista con un nodo
     * @param n Puntero al nodo cabeza
     */
    Lista (std::Nodo *n);
    /**
     * @brief Destructor que libera la memoria de todos los nodos
     */
    ~Lista();
    /**
     * @brief Agrega un elemento al inicio de la lista
     * @param d Dato a agregar
     */
    void agregar (int d);
    /**
     * @brief Verifica si la lista está vacía
     * @return true si la lista está vacía, false en caso contrario
     */
    bool es_vacia ();
    /**
     * @brief Obtiene el dato del primer nodo
     * @return Dato del primer nodo, o -1 si la lista está vacía
     */
    int get_cabeza ();
    /**
     * @brief Obtiene una nueva lista con todos los elementos excepto el primero
     * @return Puntero a una nueva Lista con el resto de elementos, o nullptr si está vacía
     */
    Lista *resto ();
    /**
     * @brief Imprime todos los elementos de la lista
     */
    void imprimir();
    /**
     * @brief Calcula el número de elementos en la lista
     * @return Cantidad de elementos en la lista
     */
    int largo();
private:
    std::Nodo *cabeza;  ///< Puntero al primer nodo de la lista
};


#endif //LISTAS_LISTA_HPP
