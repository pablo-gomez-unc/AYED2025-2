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
    ~Lista();
    void agregar_inicio (T valor);
    void agregar_final (T valor);
    void agregar_posicion (T valor, int posicion);
    void eliminar (T valor);
    void eliminar_posicion (int posicion);
    bool es_vacia ();
    int tamanio();
    void imprimir();
private:
    Nodo<T> *cabeza;
};

template <typename T>
Lista<T>::Lista() {
    cabeza = nullptr;
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
void Lista<T>::agregar_inicio(T valor) { // CABEZA -> 0 -> 1 - > 2 - > 3 -> NULL
    auto *nuevo = new Nodo<T>(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

template <typename T>
void Lista<T>::agregar_final(T valor) { // CABEZA ->  [1,*] -> [2,*] -> [3,*] -> [0,*] -> NULL
    auto *nuevo = new Nodo<T>(valor);
    if (es_vacia()) {
        cabeza = nuevo;
        return;
    }
    Nodo<T>* temp = cabeza;
    while (temp->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
}

template <typename T>
void Lista<T>::agregar_posicion(T valor, int posicion) {
    if (posicion < 0 || posicion > tamanio()-1) {
        std::cout << "posicion inválida" << std::endl;
        return;
    }

    if (posicion == 0){
        agregar_inicio(valor);
        return;
    }

    auto *nuevo = new Nodo<T>(valor); // CABEZA ->  [1,*] -> [2,*] -> [4,*] -> [3,*] -> [0,*] -> NULL
    Nodo<T>* temp = cabeza;
    int contador = 1;
    while (temp != nullptr && contador < posicion) {
        temp = temp->siguiente;
        contador++;
    }
    nuevo->siguiente = temp->siguiente;
    temp->siguiente = nuevo;
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
void Lista<T>::eliminar(T valor) { // HEAD - 1 - 2 - 3 - 1 
    if (es_vacia()) {
        std::cout << "Lista vacia";
        return;
    }

    Nodo<T>* temp = cabeza;
    if (temp != nullptr && temp->dato == valor) {
        cabeza = temp->siguiente;
        delete temp;
        return;
    }

    //CABEZA ->  [9,*] -> [0,*] -> [1,*] -> [2,*] -> NULL
    //CABEZA ->  [9,*] -> [4,*] -> [3,*] -> [2,*] -> [1,*] -> NULL 
    while (temp->siguiente != nullptr) {
        if (temp->siguiente->dato == valor) {
            Nodo<T>* aBorrar = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            delete aBorrar;
            return;
        }
        temp = temp->siguiente;
    }
}

template<typename T>
void Lista<T>::eliminar_posicion(int posicion){
    if (posicion < 0 || posicion > tamanio()-1) {
        std::cout << "posicion inválida" << std::endl;
        return;
    }

    Nodo<T>* temp = cabeza;
    if (posicion == 0) {
        cabeza = temp->siguiente;
        delete temp;
        return;
    }

    // HEAD - 4 - 2 - 1 - 0
    int contador = 1;
    while (temp-> siguiente != nullptr && contador < posicion) {
        temp = temp->siguiente;
        contador++;
    }
    Nodo<T>* aBorrar = temp->siguiente;
    temp->siguiente = temp->siguiente->siguiente;
    delete aBorrar;
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

#endif //LISTAS_LISTA_HPP
