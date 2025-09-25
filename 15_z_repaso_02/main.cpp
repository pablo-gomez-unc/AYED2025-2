#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>

// Simula un sistema de compra en línea utilizando una pila y una cola.
// Pila de "Deshacer" (Pila de Acciones): Cuando un usuario agrega un artículo al carrito,
// la acción se "empuja" en una pila.
// Si el usuario hace clic en "Deshacer", la última acción se "desapila" y el artículo se elimina del carrito.
// Cola de "Rehacer" (Cola de Acciones Deshechas): Si el usuario hace clic en "Rehacer" (después de un "Deshacer"),
// la acción se mueve de una cola de "Rehacer" a la pila principal.
// Mantén un límite para la cantidad de acciones que se pueden "deshacer" para evitar un consumo excesivo de memoria.
struct Producto
{
    int precio;
    std::string identificador;
};

class Carrito
{
public:
    void agregarProducto(Producto *p)
    {
        while (!rehacer.empty())
        {
            rehacer.pop();
        }
        deshacer.push(std::pair{p, "agregar"});
        carrito.push_back(p);
    };
    void removerProducto(Producto *p)
    {
        while (!rehacer.empty())
        {
            rehacer.pop();
        }
        deshacer.push(std::pair{p, "remover"});
        carrito.remove(p);
    };
    void deshacerOperacion()
    {
        if (deshacer.empty())
        {
            std::cout << "No hay operaciones para deshacer." << std::endl;
            return;
        }
        auto operacion = deshacer.top();
        deshacer.pop();
        if (operacion.second == "agregar")
        {
            carrito.remove(operacion.first);
        }
        else
        {
            carrito.push_back(operacion.first);
        }
        rehacer.push(operacion);
    };
    void rehacerOperacion()
    {
        auto operacion = rehacer.back();
        rehacer.pop();
        if (operacion.second == "agregar")
        {
            carrito.push_back(operacion.first);
        }
        else
        {
            carrito.remove(operacion.first);
        }
        deshacer.push(operacion);
    };

private:
    std::list<Producto *> carrito;
    std::queue<std::pair<Producto *, std::string>> rehacer;
    std::stack<std::pair<Producto *, std::string>> deshacer;
};

// queue , push , pop
// stack , push , pop
int main()
{
    Producto p1{1000, "producto 1"};
    Producto p2{2000, "producto 2"};
    Producto p3{3000, "producto 3"};

    Carrito c;
    c.agregarProducto(&p1);
    c.agregarProducto(&p2);
    c.agregarProducto(&p3);

    c.deshacerOperacion();
    c.rehacerOperacion();

    c.deshacerOperacion();
    c.deshacerOperacion();
    c.deshacerOperacion();

    c.agregarProducto(&p3);
    c.agregarProducto(&p2);
    c.agregarProducto(&p1);

    c.deshacerOperacion();
    c.deshacerOperacion();

    c.agregarProducto(&p1);

    return 0;
}
