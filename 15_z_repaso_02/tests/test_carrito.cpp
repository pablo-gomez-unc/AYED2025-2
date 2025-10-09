#include "gtest/gtest.h"
#include "../producto.hpp"  
#include "../carrito.hpp"  

class CarritoTest : public ::testing::Test {
protected:
    Carrito carrito;
    Producto p1{100, "P1"};
    Producto p2{200, "P2"};
    Producto p3{300, "P3"};

    // Helper para verificar el contenido del carrito
    void verificarContenido(const std::vector<std::string>& ids_esperados) {
        auto productos = carrito.getProductos();
        ASSERT_EQ(productos.size(), ids_esperados.size());
        
        auto it = productos.begin();
        for (auto id_esperado : ids_esperados) {
            ASSERT_EQ((*it).id, id_esperado);
            ++it;
        }
    }
};

TEST_F(CarritoTest, AgregarProducto) {
    carrito.agregarProducto(p1);
    verificarContenido({"P1"});

    carrito.agregarProducto(p2);
    verificarContenido({"P1", "P2"});
}

TEST_F(CarritoTest, RemoverProducto) {
    carrito.agregarProducto(p1);
    carrito.agregarProducto(p2);
    carrito.agregarProducto(p3);

    carrito.removerProducto(p2);
    verificarContenido({"P1", "P3"});
}

TEST_F(CarritoTest, DeshacerAgregar) {
    carrito.agregarProducto(p1);
    carrito.agregarProducto(p2);
    verificarContenido({"P1", "P2"});

    carrito.deshacerOperacion();
    verificarContenido({"P1"});

    carrito.deshacerOperacion();
    verificarContenido({});
}

TEST_F(CarritoTest, DeshacerRemover) {
    carrito.agregarProducto(p1);
    carrito.agregarProducto(p2);
    carrito.removerProducto(p1);
    verificarContenido({"P2"});

    carrito.deshacerOperacion(); // Deshace el remover(p1)
    verificarContenido({"P2", "P1"}); // El producto se agrega al final
}

TEST_F(CarritoTest, RehacerOperacion) {
    carrito.agregarProducto(p1);
    carrito.agregarProducto(p2);
    carrito.deshacerOperacion(); // Carrito: {P1}
    verificarContenido({"P1"});

    carrito.rehacerOperacion(); // Rehace agregar(p2) -> Carrito: {P1, P2}
    verificarContenido({"P1", "P2"});
}

TEST_F(CarritoTest, NuevaAccionLimpiaRehacer) {
    carrito.agregarProducto(p1);
    carrito.agregarProducto(p2);
    carrito.deshacerOperacion(); // Carrito: {P1}, Rehacer tiene {agregar, p2}
    verificarContenido({"P1"});

    carrito.agregarProducto(p3); // Carrito: {P1, P3}, Rehacer debería estar vacío
    verificarContenido({"P1", "P3"});

    // Intentar rehacer no debe tener efecto
    carrito.rehacerOperacion();
    verificarContenido({"P1", "P3"});
}

TEST_F(CarritoTest, OperacionesEnVacio) {
    ASSERT_NO_THROW(carrito.deshacerOperacion());
    ASSERT_NO_THROW(carrito.rehacerOperacion());
    EXPECT_EQ(carrito.getProductos().size(), 0);
}