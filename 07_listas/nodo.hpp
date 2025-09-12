//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_NODO_HPP
#define LISTAS_NODO_HPP

namespace std {
    struct Nodo{
        int dato;
        Nodo *siguiente;
        Nodo(int a);
        void imprimir();
    };

} // std

#endif //LISTAS_NODO_HPP
