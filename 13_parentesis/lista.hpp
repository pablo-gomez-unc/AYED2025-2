//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_LISTA_HPP
#define LISTAS_LISTA_HPP

#include <iostream>
#include "nodo.hpp"

template <typename T>
class Lista
{
public:
    Lista();
    ~Lista();
    void agregar_inicio(T valor);
    void agregar_final(T valor);
    void eliminar_inicio();
    void eliminar_final();
    T inicio();
    T final();
    bool es_vacia();
    int tamanio();
    void imprimir();

private:
    Nodo<T> *cabeza;
};

template <typename T>
Lista<T>::Lista()
{
    cabeza = nullptr;
}

template <typename T>
Lista<T>::~Lista()
{
    Nodo<T> *actual = cabeza;
    while (actual != nullptr)
    {
        Nodo<T> *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

template <typename T>
T Lista<T>::inicio()
{
    if (es_vacia())
    {
        throw std::runtime_error("Lista vacia");
    }
    return cabeza->dato;
}

template <typename T>
T Lista<T>::final()
{
    if (es_vacia())
    {
        throw std::runtime_error("Lista vacia");
    }

    Nodo<T> *temp = cabeza;
    while (temp->siguiente != nullptr)
    {
        temp = temp->siguiente;
    }
    return temp->dato;
}

template <typename T>
void Lista<T>::agregar_inicio(T valor)
{
    auto *nuevo = new Nodo<T>(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

template <typename T>
void Lista<T>::agregar_final(T valor)
{
    auto *nuevo = new Nodo<T>(valor);
    if (es_vacia())
    {
        cabeza = nuevo;
        return;
    }
    Nodo<T> *temp = cabeza;
    while (temp->siguiente != nullptr)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
}

template <typename T>
bool Lista<T>::es_vacia()
{
    return cabeza == nullptr;
}

template <typename T>
int Lista<T>::tamanio()
{
    int contador = 0;
    Nodo<T> *temp = cabeza;
    while (temp != nullptr)
    {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

template <typename T>
void Lista<T>::eliminar_inicio()
{
    if (es_vacia())
    {
        throw std::runtime_error("Lista vacia");
    }

    Nodo<T> *temp = cabeza;
    cabeza = temp->siguiente;
    delete temp;
}

template <typename T>
void Lista<T>::eliminar_final()
{
    if (es_vacia())
    {
        throw std::runtime_error("Lista vacia");
    }

    // Caso de lista que tiene un solo nodo
    if (cabeza->siguiente == nullptr)
    {
        delete cabeza;
        cabeza = nullptr;
        return;
    }

    Nodo<T> *temp = cabeza;
    while (temp->siguiente->siguiente != nullptr)
    { // Se detiene en el penultimo nodo
        temp = temp->siguiente;
    }

    delete temp->siguiente; // Eliminar el último nodo
    temp->siguiente = nullptr;
}

template <typename T>
void Lista<T>::imprimir()
{
    std::cout << "Lista: ";
    Nodo<T> *temp = cabeza;
    while (temp != nullptr)
    {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL\n";
}

#endif // LISTAS_LISTA_HPP
