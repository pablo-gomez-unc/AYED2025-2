#include <iostream>
#include "carrito.hpp"
#include "producto.hpp"

int main()
{
    Producto p1{1000, "P1"};
    Producto p2{2000, "P2"};
    Producto p3{3000, "P3"};

    Carrito c;
    c.agregarProducto(p1);
    c.agregarProducto(p2);
    c.agregarProducto(p3);
    std::cout << "Carrito inicial con 3 productos." << std::endl;

    c.deshacerOperacion();
    std::cout << "Deshacer: se quita P3." << std::endl;
    c.rehacerOperacion();
    std::cout << "Rehacer: se agrega P3 de nuevo." << std::endl;

    c.deshacerOperacion();
    c.deshacerOperacion();
    std::cout << "Se deshacen 2 operaciones." << std::endl;

    c.agregarProducto(p1);
    std::cout << "Se agrega P1. El historial de 'rehacer' se borra." << std::endl;

    return 0;
}