//
// Created by Roberto Pablo Gomez on 26/03/2025.
//

#ifndef LISTAS_LISTA_HPP
#define LISTAS_LISTA_HPP

#include "nodo.hpp"

class Lista {
public:
    Lista ();
    Lista (std::Nodo *n);
    ~Lista();
    void agregar (int d);
    bool es_vacia ();
    int get_cabeza ();
    Lista *resto ();
    void imprimir();
    int largo();
private:
    std::Nodo *cabeza;
};


#endif //LISTAS_LISTA_HPP
