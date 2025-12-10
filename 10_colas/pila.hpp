/**
 * @file pila.hpp
 * @brief Definición de la clase Pila genérica (estructura LIFO)
 * @author Roberto Pablo Gomez
 * @date 26/03/2025
 */

#ifndef LISTAS_PILA_HPP
#define LISTAS_PILA_HPP

#include <iostream>
#include "nodo.hpp"

/**
 * @class Pila
 * @brief Clase genérica que representa una pila (estructura LIFO)
 * @tparam T Tipo de dato almacenado en la pila
 */
template <typename T>
class Pila {
public:
    /**
     * @brief Constructor por defecto (pila vacía)
     */
    Pila ();
    /**
     * @brief Destructor que libera la memoria de todos los nodos
     */
    ~Pila();
    /**
     * @brief Apila un elemento en la cima de la pila
     * @param valor Valor a apilar
     */
    void apilar (T valor);
    /**
     * @brief Desapila y retorna el elemento de la cima
     * @return Valor desapilado
     */
    T desapilar ();
    /**
     * @brief Verifica si la pila está vacía
     * @return true si la pila está vacía, false en caso contrario
     */
    bool es_vacia ();
    /**
     * @brief Obtiene el tamaño de la pila
     * @return Número de elementos en la pila
     */
    int tamanio();
    /**
     * @brief Imprime todos los elementos de la pila
     */
    void imprimir();
private:
    Nodo<T> *cima;  ///< Puntero al nodo de la cima
};

template <typename T>
Pila<T>::Pila() {
    cima = nullptr;
}

template <typename T>
Pila<T>::~Pila() {
    Nodo<T>* temp = cima;
    while (temp != nullptr) {
        Nodo<T>* aux = temp;
        temp = aux->siguiente;
        delete aux;
    }
}

template <typename T>
void Pila<T>::apilar(T valor) { // Pila: 10 - 20 <- Cima
    auto *nuevo = new Nodo<T>(valor);
    if (es_vacia()) {
        cima = nuevo;
        return;
    }
    nuevo->siguiente = cima;
    cima = nuevo;
}

template <typename T>
bool Pila<T>::es_vacia() {
    return cima == nullptr;
}

template <typename T>
int Pila<T>::tamanio() {
    int contador = 0;
    Nodo<T>* temp = cima;
    while (temp != nullptr) {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

template<typename T>
T Pila<T>::desapilar() { // Pila: 10 <- Cima
    T a;
    if (es_vacia()) {
        std::cout << "Pila vacía" << std::endl;
        return a;
    }

    Nodo<T>* temp = cima;
    auto valor = temp->dato;
    cima = cima->siguiente;
    delete temp;
    return valor;
}

template <typename T>
void Pila<T>::imprimir() {
    Nodo<T>* temp = cima;
    std::cout << "Pila: Cima -> ";
    while (temp != nullptr) {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << " NULL\n";
}

#endif //LISTAS_PILA_HPP
