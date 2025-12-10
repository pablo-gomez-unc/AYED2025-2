/**
 * @file carrito.hpp
 * @brief Definición de la clase Carrito con funcionalidad de deshacer/rehacer
 * @author Roberto Pablo Gomez
 */

#ifndef CARRITO_HPP
#define CARRITO_HPP

#include "producto.hpp"
#include <list>
#include <stack>
#include <string>

/**
 * @class Carrito
 * @brief Clase que representa un carrito de compras con funcionalidad de deshacer/rehacer
 */
class Carrito
{
public:
    /**
     * @brief Agrega un producto al carrito
     * @param p Producto a agregar
     */
    void agregarProducto(const Producto& p);
    /**
     * @brief Remueve un producto del carrito
     * @param p Producto a remover
     */
    void removerProducto(const Producto& p);
    /**
     * @brief Deshace la última operación realizada
     */
    void deshacerOperacion();
    /**
     * @brief Rehace la última operación deshecha
     */
    void rehacerOperacion();

    /**
     * @brief Obtiene la lista de productos en el carrito
     * @return Referencia constante a la lista de productos
     */
    const std::list<Producto>& getProductos() const;

private:
    std::list<Producto> carrito;  ///< Lista de productos en el carrito
    std::stack<std::pair<Producto, std::string>> rehacer;  ///< Pila de operaciones para rehacer
    std::stack<std::pair<Producto, std::string>> deshacer;  ///< Pila de operaciones para deshacer
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

