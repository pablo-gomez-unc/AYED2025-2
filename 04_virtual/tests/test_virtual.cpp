/**
 * @file test_virtual.cpp
 * @brief Tests unitarios para las clases Forma y Circulo con métodos virtuales
 * @author Roberto Pablo Gomez
 */

#include <gtest/gtest.h>
#include "../Forma.hpp"
#include "../Circulo.hpp"

/**
 * @brief Test para verificar la creación de una Forma
 */
TEST(VirtualTest, FormaCreation) {
    Forma f;
    SUCCEED();
}

/**
 * @brief Test para verificar la creación de un Circulo
 */
TEST(VirtualTest, CirculoCreation) {
    Circulo c;
    SUCCEED();
}

/**
 * @brief Test para verificar el polimorfismo con métodos virtuales
 */
TEST(VirtualTest, PolymorphicCall) {
    Forma* forma = new Circulo();
    forma->dibujar(); // This will call Circulo::dibujar
    delete forma;
    SUCCEED();
}
