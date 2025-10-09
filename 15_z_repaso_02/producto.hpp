#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <string>

struct Producto
{
    int precio;
    std::string id;

    bool operator==(const Producto& other) const;
};

#endif // PRODUCTO_HPP