/**
 * @file producto.hpp
 * @brief Definición de la estructura Producto
 * @author Roberto Pablo Gomez
 */

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <string>

/**
 * @struct Producto
 * @brief Estructura que representa un producto con precio e ID
 */
struct Producto
{
    int precio;        ///< Precio del producto
    std::string id;    ///< Identificador del producto

    /**
     * @brief Operador de igualdad para comparar productos
     * @param other Otro producto a comparar
     * @return true si los productos tienen el mismo ID, false en caso contrario
     */
    bool operator==(const Producto& other) const;
};

#endif // PRODUCTO_HPP