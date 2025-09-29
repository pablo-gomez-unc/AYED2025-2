//
// Created by Roberto Pablo Gomez on 31/03/2025.
//
#include "gtest/gtest.h"
#include "../sorting.hpp"

TEST(SwapTest, IntercambiaCorretamente) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};

    swap(array[1], array[2]);
    ASSERT_EQ(array[1], 25);
    ASSERT_EQ(array[2], 34);
}

TEST(IgualesTest, ValidaCorrectamenteArraysIguales) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int array2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);
    ASSERT_TRUE(iguales(array, array2, n));
}

TEST(IgualesTest, ValidaCorrectamenteArraysDistintos) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int array2[] = {64, 34, 25, 12, 22, 11, 1};
    int n = sizeof(array) / sizeof(array[0]);
    ASSERT_FALSE(iguales(array, array2, n));
}

TEST(BubbleSortTest, OrdenaCorrectamente) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(array) / sizeof(array[0]);

    burbuja(array, n);
    ASSERT_TRUE(iguales(array, expected, n));
}

TEST(BubbleSortRecTest, OrdenaCorrectamente) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(array) / sizeof(array[0]);

    burbuja_recursivo(array, n, 0);
    ASSERT_TRUE(iguales(array, expected, n));
}

TEST(SelectionSortTest, OrdenaCorrectamente) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(array) / sizeof(array[0]);

    seleccion(array, n);
    ASSERT_TRUE(iguales(array, expected, n));
}

TEST(SelectionSortRecTest, OrdenaCorrectamente) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(array) / sizeof(array[0]);

    seleccion_recursivo(array, n, 0);
    ASSERT_TRUE(iguales(array, expected, n));
}

TEST(InsertionSortTest, OrdenaCorrectamente) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(array) / sizeof(array[0]);

    insercion(array, n);
    ASSERT_TRUE(iguales(array, expected, n));
}

TEST(InsertionSortRecTest, OrdenaCorrectamente) {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(array) / sizeof(array[0]);

    insercion_recursivo(array, n, 1);
    ASSERT_TRUE(iguales(array, expected, n));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}