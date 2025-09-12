#include <iostream>
#include "cola.hpp"
#include "pila.hpp"

int main() {
    std::cout << "Pilas 2025" << std::endl;
    auto *p = new Pila<int>();
    p->apilar(1);
    p->apilar(2);
    p->apilar(3);
    p->apilar(4);
    p->imprimir();
    int valor = p->desapilar();
    std::cout << "Desapilado - Nodo con valor: " << valor << std::endl;
    p->imprimir();

    valor = p->desapilar();
    std::cout << "Desapilado - Nodo con valor: " << valor << std::endl;
    valor = p->desapilar();
    std::cout << "Desapilado - Nodo con valor: " << valor << std::endl;
    p->imprimir();
    delete p;


    std::cout << "Colas 2025" << std::endl;
    auto *c = new Cola<int>();
    c->encolar(1);
    c->encolar(0);
    c->encolar(2);
    c->imprimir();

    valor = c->desencolar();
    std::cout << "Desencolado - Nodo con valor: " << valor << std::endl;
    c->imprimir();

    valor = c->desencolar();
    std::cout << "Desencolado - Nodo con valor: " << valor << std::endl;
    c->imprimir_rec();

    valor = c->desencolar();
    std::cout << "Desencolado - Nodo con valor: " << valor << std::endl;
    c->imprimir_rec();

    delete c;
    return 0;
}
