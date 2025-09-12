//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_COLA_HPP
#define LISTAS_COLA_HPP

#include <iostream>

template <typename T, int N>
class Cola {
public:
    Cola ();
    ~Cola();
    void encolar (T valor);
    T desencolar ();
    bool es_vacia ();
    int get_tamanio();
    void imprimir();
private:
    T* inicio;
    T* final;
    T* array;
    int tamanio;
    int n = N;
};

template <typename T, int N>
Cola<T,N>::Cola() {
    array = new T[N];
    inicio = nullptr;
    final = nullptr;
}

template <typename T, int N>
Cola<T,N>::~Cola() {
    delete[] array;
}

template <typename T, int N>
void Cola<T,N>::encolar(T valor) {
    tamanio++;
    if (es_vacia()) {
        *array = valor;
        inicio = final = array;
        return;
    }
    final = final+1;
    *final = valor;
}

template <typename T, int N>
bool Cola<T,N>::es_vacia() {
    return final == nullptr && inicio == nullptr;
}

template <typename T, int N>
int Cola<T,N>::get_tamanio() {
    return tamanio;
}

template <typename T, int N>
T Cola<T,N>::desencolar() {  // _ _ _ 4 3
    if (es_vacia()) {
        throw std::out_of_range("Cola vacia");
    }
    T valor = *inicio;
    inicio = inicio+1;
    tamanio--;
    return valor;
}

template <typename T, int N>
void Cola<T,N>::imprimir() {
    std::cout << "Cola: INICIO -> ";
    for (int i = 0; i < tamanio; i++){
        std::cout <<  inicio[i] <<  " -> ";
    }
    std::cout << "FINAL\n";
}

#endif //LISTAS_COLA_HPP
