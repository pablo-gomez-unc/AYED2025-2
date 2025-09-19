//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_LISTA_HPP
#define LISTAS_LISTA_HPP

#include <iostream>
#include "nodo.hpp"

template <typename T>
class Lista {
public:
    Lista ();
    Lista (Nodo<T>* n);
    ~Lista();
    void agregar (T valor);
    T eliminar ();
    void invertir ();
    bool es_vacia ();
    Nodo<T>* encontrar_punto_medio();
    int tamanio();
    void imprimir();
    void mezclar(Lista<T> &lista1, Lista<T> &lista2);
private:
    Nodo<T> *cabeza;
};

template <typename T>
Lista<T>::Lista() {
    cabeza = nullptr;
}

template <typename T>
Lista<T>::Lista(Nodo<T>* n) {
    cabeza = n;
}

template <typename T>
Lista<T>::~Lista() {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        Nodo<T>* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

template <typename T>
void Lista<T>::agregar (T valor) { // CABEZA -> 0 -> 1 - > 2 - > 3 -> NULL
    auto *nuevo = new Nodo<T>(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

template <typename T>
bool Lista<T>::es_vacia() {
    return cabeza == nullptr;
}

template <typename T>
int Lista<T>::tamanio() {
    int contador = 0;
    Nodo<T>* temp = cabeza;
    while (temp != nullptr) {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

template<typename T>
T Lista<T>::eliminar() {
    if (es_vacia()) {
        T a;
        return a;
    }
    T valor = cabeza->dato;
    cabeza = cabeza->siguiente;
    return valor;
}

template <typename T>
void Lista<T>::imprimir() {
    std::cout << "Lista: ";
    Nodo<T>* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL\n";
}

template <typename T>
Nodo<T>* Lista<T>::encontrar_punto_medio() {
    Nodo<T>* lento = cabeza;
    Nodo<T>* rapido = cabeza;
    while (rapido != nullptr && rapido->siguiente != nullptr) {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }
    return lento;
}

template <typename T>
void Lista<T>::invertir() {
    Nodo<T>* prev = nullptr;
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        Nodo<T>* temp = actual->siguiente;
        actual->siguiente = prev;
        prev = actual;
        actual = temp;
    }
    cabeza = prev;
}

template <typename T>
void Lista<T>::mezclar(Lista<T> &lista1, Lista<T> &lista2){
    int tamLista1 = lista1.tamanio();
    int tamLista2 = lista2.tamanio();
    for (int i = 0; i < tamLista1; i++){
        this->agregar(lista1.eliminar());
        if (i < tamLista2) {
            this->agregar(lista2.eliminar());
        }
    }
}

#endif //LISTAS_LISTA_HPP