//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_PILA_HPP
#define LISTAS_PILA_HPP

#include <iostream>
#include "nodo.hpp"

template <typename T>
class Pila {
public:
    Pila ();
    ~Pila();
    void apilar (T valor);
    T desapilar ();
    bool es_vacia ();
    int tamanio();
    void imprimir();
private:
    Nodo<T> *cima;
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
