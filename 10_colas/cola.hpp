/**
 * @file cola.hpp
 * @brief Definición de la clase Cola genérica (estructura FIFO)
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#ifndef LISTAS_COLA_HPP
#define LISTAS_COLA_HPP

#include <iostream>
#include "nodo.hpp"

/**
 * @class Cola
 * @brief Clase genérica que representa una cola (estructura FIFO)
 * @tparam T Tipo de dato almacenado en la cola
 */
template <typename T>
class Cola {
public:
    /**
     * @brief Constructor por defecto (cola vacía)
     */
    Cola ();
    /**
     * @brief Destructor que libera la memoria de todos los nodos
     */
    ~Cola();
    /**
     * @brief Encola un elemento al final de la cola
     * @param valor Valor a encolar
     */
    void encolar (T valor);
    /**
     * @brief Desencola y retorna el elemento del inicio
     * @return Valor desencolado
     */
    T desencolar ();
    /**
     * @brief Verifica si la cola está vacía
     * @return true si la cola está vacía, false en caso contrario
     */
    bool es_vacia ();
    /**
     * @brief Obtiene el tamaño de la cola
     * @return Número de elementos en la cola
     */
    int tamanio();
    /**
     * @brief Imprime todos los elementos de la cola (iterativo)
     */
    void imprimir();
    /**
     * @brief Imprime todos los elementos de la cola (recursivo)
     */
    void imprimir_rec();
private:
    Nodo<T> *inicio;  ///< Puntero al primer nodo de la cola
    Nodo<T> *final;    ///< Puntero al último nodo de la cola
    /**
     * @brief Función auxiliar recursiva para imprimir
     * @param temp Puntero al nodo actual
     */
    void imprimir_aux(Nodo<T>* temp);
};

template <typename T>
Cola<T>::Cola() {
    inicio = nullptr;
    final = nullptr;
}

template <typename T>
Cola<T>::~Cola() {
    Nodo<T>* temp = inicio;
    while (temp != nullptr) {
        Nodo<T>* aux = temp;
        temp = aux->siguiente;
        delete aux;
    }
}

template <typename T> // Cola :  Inicio -> 10|sig <- Final 
                      // Cola :  Inicio -> 10|sig - 20 <- Final
void Cola<T>::encolar(T valor) {
    auto *nuevo = new Nodo<T>(valor);

    if (es_vacia()) {
        inicio = final = nuevo;
        return;
    }

    final->siguiente = nuevo;
    final = nuevo;
}

template <typename T>
bool Cola<T>::es_vacia() {
    return final == nullptr && inicio == nullptr;
}

template <typename T>
int Cola<T>::tamanio() {
    int contador = 0;
    Nodo<T>* temp = final;
    while (temp != nullptr) {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

template<typename T>
T Cola<T>::desencolar() { // Cola : Inicio ->  20 <- Final. 
    T a;
    if (es_vacia()) {
        std::cout << "Cola vacía" << std::endl;
        return a;
    }

    Nodo<T>* temp = inicio;
    inicio = inicio->siguiente;
    if (inicio == nullptr) {
        final = nullptr;
    }

    T valor = temp->dato;
    delete temp;
    return valor;
}

template <typename T>
void Cola<T>::imprimir() {
    Nodo<T>* temp = inicio;
    std::cout << "Cola: INICIO -> ";
    while (temp != nullptr) {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << " FINAL\n";
}

template <typename T>
void Cola<T>::imprimir_aux(Nodo<T>* temp) {
    if (temp == nullptr) {
        return;
    }
    std::cout << temp->dato << " -> ";
    imprimir_aux(temp->siguiente);
}

template <typename T>
void Cola<T>::imprimir_rec() {
    Nodo<T>* temp = inicio;
    std::cout << "Cola: INICIO -> ";
    imprimir_aux(temp);
    std::cout << " FINAL\n";
}

#endif //LISTAS_COLA_HPP
