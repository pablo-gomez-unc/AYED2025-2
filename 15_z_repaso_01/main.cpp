#include <iostream>
#include <vector>

#include "lista.hpp"

// Escribe un algoritmo para reorganizar una lista enlazada simple de forma
// que los nodos se alternen desde el inicio y el final de la lista original.
// Ejemplo: Si la lista es 1 -> 2 -> 3 -> 4 -> 5 -> 6,
// el resultado debería ser 1 -> 6 -> 2 -> 5 -> 3 -> 4.
// Proceso:
//     - Encontrar el punto medio
//     - Dividir la lista en dos   1 2 3      4 5 6
//     - Invertir la segunda mitad 1 2 3      6 5 4
//     - Fusionar las dos listas de manera alternada.   1 6 2 5 3 4


int main() {
    auto lista = Lista<int>();
    lista.agregar(6);
    lista.agregar(5);
    lista.agregar(4);
    lista.agregar(3);
    lista.agregar(2);
    lista.agregar(1);
    lista.imprimir();

    auto puntoMedio = lista.encontrar_punto_medio();
    std::cout << puntoMedio->dato << std::endl;
    auto lista2 = Lista(puntoMedio->siguiente);
    puntoMedio->siguiente = nullptr;
    lista.imprimir();
    lista2.imprimir();

    lista2.invertir();
    lista2.imprimir();

    auto listaUnion = Lista<int>();
    listaUnion.mezclar(lista, lista2);
    listaUnion.invertir();
    listaUnion.imprimir();

    std::vector<int> vectorCompleto { 1 , 2 , 3 ,4 , 5, 6};
    std::vector<int> vector1;
    std::vector<int> vector2;
    int indiceMedio = vectorCompleto.size()/2;
    for (int i = 0; i < vectorCompleto.size(); i++){
        if (i < indiceMedio){
            vector1.push_back(vectorCompleto[i]);
            continue;
        }
        vector2.push_back(vectorCompleto[i]);
    }

    int offset = 0;
    for (int i = 0; i < vectorCompleto.size(); i++){
        if (i%2 == 0) {
            vectorCompleto[i] = vector1[i-offset];
            offset++;
            continue;
        }
        vectorCompleto[i] = vector2[vector2.size()-offset];
    }

    return 0;
}

