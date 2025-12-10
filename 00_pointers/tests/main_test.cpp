/**
 * @file main_test.cpp
 * @brief Tests unitarios para las funciones de punteros y referencias
 * @author Roberto Pablo Gomez
 */

#include <gtest/gtest.h>
#include "../funciones.hpp"

/**
 * @brief Test para verificar que funcValorRef modifica el valor por referencia
 */
TEST(FuncTests, RefTest) {
    int x = 5;
    funcValorRef(x);
    EXPECT_EQ(x, 10);
}

/**
 * @brief Test para verificar que funcValorCopia no modifica el valor original
 */
TEST(FuncTests, ValueTest) {
    int x = 5;
    funcValorCopia(x);
    EXPECT_EQ(x, 5);
}