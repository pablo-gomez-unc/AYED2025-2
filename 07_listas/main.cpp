#include <iostream>
#include "nodo.hpp"
#include "lista.hpp"

int main() {
    std::cout << "Listas 2025" << std::endl;

    std::cout << "+++++++ Nodos ++++++" << std::endl;
    std::Nodo n {1};
    std::cout << n.dato << std::endl;

    std::Nodo n1 {2};
    std::Nodo n2 {3};
    n1.siguiente = &n2;
    n.siguiente = &n1;
    std::cout << "---" << std::endl;
    std::cout << n.dato << std::endl;
    std::cout << n.siguiente << std::endl;
    std::cout << "---" << std::endl;
    std::cout << n.siguiente->dato << std::endl;
    std::cout << n.siguiente->siguiente << std::endl;
    std::cout << "---" << std::endl;
    std::cout << n.siguiente->siguiente->dato << std::endl;
    std::cout << n.siguiente->siguiente->siguiente << std::endl;
    std::cout << "---" << std::endl;

    std::cout << "+++++ Listas ++++++" << std::endl;
    Lista *l = new Lista();
    l->imprimir();
    std::cout << "es_vacia: " <<  l->es_vacia() << std::endl;
    std::cout << "cabeza: " << l->get_cabeza() << std::endl;
    //l->resto()->imprimir();
    std::cout <<  "largo lista: " << l->largo() << std::endl;
    std::cout << "---" << std::endl;
    delete l;

    Lista *l1 = new Lista(new std::Nodo(1));
    l1->imprimir();
    std::cout << "es_vacia: " << l1->es_vacia() << std::endl;
    std::cout << "cabeza: " << l1->get_cabeza() << std::endl;
    l1->resto()->imprimir();
    std::cout << "---" << std::endl;

    l1->agregar(2);
    l1->agregar(3);
    l1->agregar(4);
    l1->imprimir();
    std::cout << "es_vacia: " << l1->es_vacia() << std::endl;
    std::cout << "cabeza: " << l1->get_cabeza() << std::endl;
    l1->resto()->imprimir();
    std::cout << "---" << std::endl;
    l1->resto()->resto()->imprimir();
    std::cout <<  "largo lista: " << l1->largo() << std::endl;
    std::cout << "---" << std::endl;
    delete l1;

    return 0;
}
