//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#include "lista.hpp"
#include <iostream>
#include <stdexcept> // For std::runtime_error


Lista::Lista() {
    cabeza = nullptr;
}

Lista::Lista(std::Nodo *n) {
    cabeza = n;
}

Lista::~Lista() {
    std::cout << "Llamando al destructor y liberando memoria..." << std::endl;
    std::Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Lista::agregar(int d) {
    auto *nuevo = new std::Nodo(d);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

bool Lista::es_vacia() {
    return cabeza == nullptr;
}

int Lista::get_cabeza() {
    if (es_vacia()) {
        //throw new std::runtime_error("Error - Lista vacia");
        return -1;
    }
    return cabeza->dato;
}

Lista *Lista::resto() {
    if (es_vacia()) {
        return nullptr;
    }
    return new Lista (cabeza->siguiente);
}

void Lista::imprimir() {
    if(resto() == nullptr) {
        return;
    }
    cabeza->imprimir();
    resto()->imprimir();
}

int Lista::largo(){
    if(resto() == nullptr) {
        return 0;
    }
    return 1 + resto()->largo();
}


