#include <iostream>
#include "lista.hpp"

template<typename T>
class Contenedor {
private:
    T dato;
public:
    Contenedor(): dato(0) { std::cout << "number" << std::endl; };
};

template<>
class Contenedor<std::string> {
private:
    std::string dato;
public:
    Contenedor(): dato("NO_INICIALIZADO") { std::cout << "string" << std::endl; };
};

int main() {
    std::cout << "Generics 2025" << std::endl;
    Contenedor<int> ci;
    Contenedor<float> cf;
    Contenedor<std::string> cs;

    auto *l = new Lista<int>();
    l->agregar(1);
    l->agregar(2);
    l->imprimir();
    delete l;

    auto *l1 = new Lista<std::string>();
    l1->agregar("hola");
    l1->agregar("chau");
    l1->imprimir();
    delete l1;

    return 0;
}
