/**
 * @file tests.cpp
 * @brief Tests unitarios para las funciones de recursión
 * @author Roberto Pablo Gomez
 */

#include <gtest/gtest.h>
#include "../functions.hpp"

/**
 * @brief Test para verificar sumatoria iterativa
 */
TEST(RecursionTests, Sumatoria){
    int resultado = sumatoriaIter(5);
    EXPECT_EQ(resultado, 15);
}

/**
 * @brief Test para verificar sumatoria recursiva con valor válido
 */
TEST(RecursionTests, SumatoriaRecOK){
    int resultado = sumatoriaRec(5);
    EXPECT_EQ(resultado, 15);
}

/**
 * @brief Test para verificar que sumatoria recursiva lanza excepción con valor negativo
 */
TEST(RecursionTests, SumatoriaRecMenor0){
    EXPECT_ANY_THROW(sumatoriaRec(-1));
}

/**
 * @brief Test para verificar sumatoria recursiva con valor cero
 */
TEST(RecursionTests,SumatoriaRecIgual0){
    int resultado = sumatoriaRec(0);
    EXPECT_EQ(resultado, 0);
}

/**
 * @brief Test para verificar Fibonacci iterativo
 */
TEST(RecursionTests, Fibonacci){
    int resultado = fibonacciIter(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciIter(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciIter(5);
    EXPECT_EQ(resultado, 5);
}

/**
 * @brief Test para verificar Fibonacci recursivo
 */
TEST(RecursionTests, FibonacciRec){
    int resultado = fibonacciRec(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciRec(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciRec(5);
    EXPECT_EQ(resultado, 5);
}

/**
 * @brief Test para verificar Fibonacci con recursión de cola
 */
TEST(RecursionTests, FibonacciTail){
    int resultado = fibonacciTail(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciTail(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciTail(5);
    EXPECT_EQ(resultado, 5);
}

/**
 * @brief Test para verificar Fibonacci iterativo optimizado
 */
TEST(RecursionTests, FibonacciTailIter){
    int resultado = fibonacciTailIter(3);
    EXPECT_EQ(resultado, 2);

    resultado = fibonacciTailIter(4);
    EXPECT_EQ(resultado, 3);

    resultado = fibonacciTailIter(5);
    EXPECT_EQ(resultado, 5);
}