//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_NODO_HPP
#define LISTAS_NODO_HPP

template <typename T>
struct Nodo{
    T dato;
    Nodo<T> *siguiente;
    Nodo(T a);
};

template<typename T>
Nodo<T>::Nodo(T a): dato(a), siguiente(nullptr) {}

#endif //LISTAS_NODO_HPP
