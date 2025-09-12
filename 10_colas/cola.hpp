//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_COLA_HPP
#define LISTAS_COLA_HPP

#include <iostream>
#include "nodo.hpp"

template <typename T>
class Cola {
public:
    Cola ();
    ~Cola();
    void encolar (T valor);
    T desencolar ();
    bool es_vacia ();
    int tamanio();
    void imprimir();
    void imprimir_rec();
private:
    Nodo<T> *inicio;
    Nodo<T> *final;
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
