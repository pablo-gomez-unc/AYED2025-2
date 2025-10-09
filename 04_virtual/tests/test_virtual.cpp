
#include <gtest/gtest.h>
#include "../Forma.hpp"
#include "../Circulo.hpp"

TEST(VirtualTest, FormaCreation) {
    Forma f;
    SUCCEED();
}

TEST(VirtualTest, CirculoCreation) {
    Circulo c;
    SUCCEED();
}

TEST(VirtualTest, PolymorphicCall) {
    Forma* forma = new Circulo();
    forma->dibujar(); // This will call Circulo::dibujar
    delete forma;
    SUCCEED();
}
