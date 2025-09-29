#include <iostream>
#include "lista.hpp"

int main() {
    std::cout << "Extension Listas 2025" << std::endl;
    auto *l = new Lista<int>();
    l->agregar_inicio(11);
    l->agregar_inicio(33);
    l->agregar_inicio(22);
    l->agregar_inicio(44);
    l->agregar_inicio(9);
    l->imprimir();
    l->ordenar_burbuja();
    l->imprimir();
    delete l;

    auto *l1 = new Lista<int>();
    l1->agregar_inicio(11);
    l1->agregar_inicio(33);
    l1->agregar_inicio(22);
    l1->agregar_inicio(44);
    l1->agregar_inicio(9);
    l1->imprimir();
    l1->ordenar_burbuja();
    l1->imprimir();
    delete l1;

    auto *l2 = new Lista<int>();
    l1->agregar_inicio(11);
    l1->agregar_inicio(33);
    l1->agregar_inicio(22);
    l1->agregar_inicio(44);
    l1->agregar_inicio(9);
    l1->imprimir();
    l1->ordenar_burbuja();
    l1->imprimir();
    delete l1;
    return 0;
}
