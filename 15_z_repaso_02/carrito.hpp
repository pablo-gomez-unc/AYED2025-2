#ifndef CARRITO_HPP
#define CARRITO_HPP

#include "producto.hpp"
#include <list>
#include <stack>
#include <string>

class Carrito
{
public:
    void agregarProducto(const Producto& p);
    void removerProducto(const Producto& p);
    void deshacerOperacion();
    void rehacerOperacion();

    const std::list<Producto>& getProductos() const;

private:
    std::list<Producto> carrito;
    std::stack<std::pair<Producto, std::string>> rehacer;
    std::stack<std::pair<Producto, std::string>> deshacer;
};

#include "carrito.hpp"

bool Producto::operator==(const Producto& other) const {
    return id == other.id;
}

void Carrito::agregarProducto(const Producto& p)
{
    while (!rehacer.empty())
    {
        rehacer.pop();
    }
    deshacer.push({p, "agregar"});
    carrito.push_back(p);
};

void Carrito::removerProducto(const Producto& p)
{
    while (!rehacer.empty())
    {
        rehacer.pop();
    }
    deshacer.push({p, "remover"});
    carrito.remove(p);
};

void Carrito::deshacerOperacion()
{
    if (deshacer.empty()) return;

    auto operacion = deshacer.top();
    deshacer.pop();
    if (operacion.second == "agregar") {
        carrito.remove(operacion.first);
    } else { 
        carrito.push_back(operacion.first);
    }
    rehacer.push(operacion);
};

void Carrito::rehacerOperacion()
{
    if (rehacer.empty()) return;

    auto operacion = rehacer.top();
    rehacer.pop();
    if (operacion.second == "agregar") {
        carrito.push_back(operacion.first);
    } else {
        carrito.remove(operacion.first);
    }
    deshacer.push(operacion);
};

const std::list<Producto>& Carrito::getProductos() const {
    return carrito;
}

#endif // CARRITO_HPP

