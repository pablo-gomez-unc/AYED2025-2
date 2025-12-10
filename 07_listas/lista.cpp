/**
 * @file lista.cpp
 * @brief Implementación de la clase Lista
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#include "lista.hpp"
#include <iostream>
#include <stdexcept> // For std::runtime_error

/**
 * @brief Constructor por defecto (lista vacía)
 */
Lista::Lista() {
    cabeza = nullptr;
}

/**
 * @brief Constructor que inicializa la lista con un nodo
 * @param n Puntero al nodo cabeza
 */
Lista::Lista(std::Nodo *n) {
    cabeza = n;
}

/**
 * @brief Destructor que libera la memoria de todos los nodos
 */
Lista::~Lista() {
    std::cout << "Llamando al destructor y liberando memoria..." << std::endl;
    std::Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

/**
 * @brief Agrega un elemento al inicio de la lista
 * @param d Dato a agregar
 */
void Lista::agregar(int d) {
    auto *nuevo = new std::Nodo(d);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

/**
 * @brief Verifica si la lista está vacía
 * @return true si la lista está vacía, false en caso contrario
 */
bool Lista::es_vacia() {
    return cabeza == nullptr;
}

/**
 * @brief Obtiene el dato del primer nodo
 * @return Dato del primer nodo, o -1 si la lista está vacía
 */
int Lista::get_cabeza() {
    if (es_vacia()) {
        //throw new std::runtime_error("Error - Lista vacia");
        return -1;
    }
    return cabeza->dato;
}

/**
 * @brief Obtiene una nueva lista con todos los elementos excepto el primero
 * @return Puntero a una nueva Lista con el resto de elementos, o nullptr si está vacía
 */
Lista *Lista::resto() {
    if (es_vacia()) {
        return nullptr;
    }
    return new Lista (cabeza->siguiente);
}

/**
 * @brief Imprime todos los elementos de la lista
 */
void Lista::imprimir() {
    if(resto() == nullptr) {
        return;
    }
    cabeza->imprimir();
    resto()->imprimir();
}

/**
 * @brief Calcula el número de elementos en la lista
 * @return Cantidad de elementos en la lista
 */
int Lista::largo(){
    if(resto() == nullptr) {
        return 0;
    }
    return 1 + resto()->largo();
}


