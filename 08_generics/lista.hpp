//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_LISTA_HPP
#define LISTAS_LISTA_HPP

#include "nodo.hpp"

template <typename T>
class Lista {
public:
    Lista ();
    ~Lista();
    void agregar (T d);
    bool es_vacia ();
    int cabeza ();
    Lista<T> *resto ();
    void imprimir();
private:
    Lista (Nodo<T>* n);
    Nodo<T> *comienzo;
};


template <typename T>
Lista<T>::Lista() {
    comienzo = nullptr;
}

template <typename T>
Lista<T>::Lista(Nodo<T>* n) {
    comienzo = n;
}

template <typename T>
Lista<T>::~Lista() {
    std::cout << "Llamando al destructor y liberando memoria..." << std::endl;
    Nodo<T>* actual = comienzo;
    while (actual != nullptr) {
        Nodo<T>* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

template <typename T>
void Lista<T>::agregar(T d) {
    auto *nuevo = new Nodo(d);
    nuevo->siguiente = comienzo;
    comienzo = nuevo;
}

template <typename T>
bool Lista<T>::es_vacia() {
    return comienzo == nullptr;
}

template <typename T>
int Lista<T>::cabeza() {
    if (es_vacia()) {
        return -1;
    }
    return comienzo->dato;
}

template <typename T>
Lista<T> *Lista<T>::resto() {
    if (es_vacia()) {
        return nullptr;
    }
    return new Lista<T> (comienzo->siguiente);
}

template <typename T>
void Lista<T>::imprimir() {
    if(resto() == nullptr) {
        return;
    }
    comienzo->imprimir();
    resto()->imprimir();
}

#endif //LISTAS_LISTA_HPP
