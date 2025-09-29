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
    void ordenar_burbuja ();
    void ordenar_seleccion ();
    void ordenar_insercion ();
    bool es_vacia ();
    bool igual (Lista<T>* lista);
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
void Lista<T>::agregar_inicio(T valor) {
    auto *nuevo = new Nodo<T>(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

template <typename T>
void Lista<T>::agregar_final(T valor) {
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

    auto *nuevo = new Nodo<T>(valor);
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
void Lista<T>::eliminar(T valor) {
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

    Nodo<T>* anterior = nullptr;
    while (temp->siguiente != nullptr) {
        anterior = temp;
        temp = temp->siguiente;
        if (temp->dato == valor) {
            anterior->siguiente = temp->siguiente;
            delete temp;
            return;
        }
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

    Nodo<T>* anterior = nullptr;
    int contador = 0;
    while (temp != nullptr && contador < posicion) {
        anterior = temp;
        temp = temp->siguiente;
        contador++;
    }
    anterior->siguiente = temp->siguiente;
    delete temp;
}

template <typename T>
void Lista<T>::imprimir() {
    Nodo<T>* temp = cabeza;
    std::cout << "Lista: ";
    while (temp != nullptr) {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL\n";
}

template <typename T>
bool Lista<T>::igual (Lista* lista){
    if (tamanio() != lista->tamanio()) { return false; }
    if (tamanio() == 0 && lista->tamanio() == 0) { return true; }

    Nodo<T>* temp = cabeza;
    Nodo<T>* tempLista = lista->cabeza;

    if (tamanio() != lista->tamanio()) {
        return false;
    }

    while (!temp) {
        if (temp->dato != tempLista->dato) {
            return false;
        }
        temp = temp->siguiente;
        tempLista = tempLista->siguiente;
    }
    return true;
}


template <typename T>
void Lista<T>::ordenar_burbuja() {
    int n = tamanio();
    for (int i=0; i < n-1; i++) {
        Nodo<T> *temp = cabeza;
        int j = 0;
        while (temp != nullptr && temp->siguiente != nullptr && j < n-i-1) {
            if (temp->dato > temp->siguiente->dato) {
                int v = temp->dato;
                temp->dato = temp->siguiente->dato;
                temp->siguiente->dato = v;
            }
            temp = temp->siguiente;
            j++;
        }
    }
}

template <typename T>
void Lista<T>::ordenar_seleccion() {
    Nodo<T>* i = cabeza;
    while (i) {
        Nodo<T>* j = i->siguiente;
        Nodo<T>* min = i;

        while (j) {
            if (j->dato < min->dato) {
                min = j;
            }
            j = j->siguiente;
        }

        if (min != i) {
            int temp = i->dato;
            i->dato = min->dato;
            min->dato = temp;
        }

        i = i->siguiente;
    }
}

template <typename T>
void Lista<T>::ordenar_insercion() {
    Nodo<T>* ordenado = nullptr;
    Nodo<T>* actual = cabeza;

    while (actual) {
        Nodo<T>* proximo = actual->siguiente;
        if (!ordenado || ordenado->dato >= actual->dato) {
            actual->siguiente = ordenado;
            ordenado = actual;
        } else {
            Nodo<T>* temp = ordenado;
            while (temp->siguiente && temp->siguiente->dato < actual->dato) {
                temp = temp->siguiente;
            }
            actual->siguiente = temp->siguiente;
            temp->siguiente = actual;
        }
        actual = proximo;
    }
    cabeza = ordenado;
}

#endif //LISTAS_LISTA_HPP
