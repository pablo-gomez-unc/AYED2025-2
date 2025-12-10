/**
 * @file main.cpp
 * @brief Ejercicio de repaso: Reorganizar lista enlazada alternando inicio y final
 * @details Implementa un algoritmo para reorganizar una lista enlazada simple
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include <vector>

#include "lista.hpp"

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
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

