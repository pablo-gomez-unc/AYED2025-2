//
// Created by Roberto Pablo Gomez on 31/03/2025.
//
#include "gtest/gtest.h"
#include "../lista.hpp"

TEST(IgualTest, ComparaIguales) {
    auto *l = new Lista<int>();
    l->agregar_inicio(11);
    l->agregar_inicio(33);

    auto *l2 = new Lista<int>();
    l2->agregar_inicio(11);
    l2->agregar_inicio(33);

    ASSERT_TRUE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(IgualTest, ComparaIgualesVacias) {
    auto *l = new Lista<int>();
    auto *l2 = new Lista<int>();

    ASSERT_TRUE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(IgualTest, ListaVacia) {
    auto *l = new Lista<int>();
    auto *l2 = new Lista<int>();
    l2->agregar_inicio(11);

    ASSERT_FALSE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(IgualTest, ListaParametroVacia) {
    auto *l = new Lista<int>();
    l->agregar_inicio(11);

    auto *l2 = new Lista<int>();

    ASSERT_FALSE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(IgualTest, ComparaDistintos) {
    auto *l = new Lista<int>();
    l->agregar_inicio(33);
    l->agregar_inicio(11);

    auto *l2 = new Lista<int>();
    l2->agregar_inicio(11);
    l2->agregar_inicio(33);

    ASSERT_TRUE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(OrdenarBurbujaTest, OrdernaCorrectamente) {
    auto *l = new Lista<int>();
    l->agregar_inicio(11);
    l->agregar_inicio(33);
    l->agregar_inicio(22);
    l->agregar_inicio(44);
    l->agregar_inicio(9);

    auto *l2 = new Lista<int>();
    l2->agregar_inicio(9);
    l2->agregar_inicio(11);
    l2->agregar_inicio(22);
    l2->agregar_inicio(33);
    l2->agregar_inicio(44);

    l->ordenar_burbuja();
    ASSERT_TRUE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(OrdenarBurbujaTest, ListaVacia) {
    auto *l = new Lista<int>();
    auto *l2 = new Lista<int>();

    l->ordenar_burbuja();
    ASSERT_TRUE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(OrdenarSeleccionTest, OrdernaCorrectamente) {
    auto *l = new Lista<int>();
    l->agregar_inicio(11);
    l->agregar_inicio(33);
    l->agregar_inicio(22);
    l->agregar_inicio(44);
    l->agregar_inicio(9);

    auto *l2 = new Lista<int>();
    l2->agregar_inicio(9);
    l2->agregar_inicio(11);
    l2->agregar_inicio(22);
    l2->agregar_inicio(33);
    l2->agregar_inicio(44);

    l->ordenar_seleccion();
    ASSERT_TRUE(l->igual(l2));
    delete l;
    delete l2;
}

TEST(OrdenarInsercionTest, OrdernaCorrectamente) {
    auto *l = new Lista<int>();
    l->agregar_inicio(11);
    l->agregar_inicio(33);
    l->agregar_inicio(22);
    l->agregar_inicio(44);
    l->agregar_inicio(9);

    auto *l2 = new Lista<int>();
    l2->agregar_inicio(9);
    l2->agregar_inicio(11);
    l2->agregar_inicio(22);
    l2->agregar_inicio(33);
    l2->agregar_inicio(44);

    l->ordenar_insercion();
    ASSERT_TRUE(l->igual(l2));
    delete l;
    delete l2;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}