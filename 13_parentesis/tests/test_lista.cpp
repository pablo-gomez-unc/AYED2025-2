#include "gtest/gtest.h"
#include "../lista.hpp"

class ListaTest : public ::testing::Test {
protected:
    Lista<int> lista;
};

TEST_F(ListaTest, InicialmenteVacia) {
    EXPECT_TRUE(lista.es_vacia());
    EXPECT_EQ(lista.tamanio(), 0);
}

TEST_F(ListaTest, AgregarInicio) {
    lista.agregar_inicio(10);
    EXPECT_FALSE(lista.es_vacia());
    EXPECT_EQ(lista.tamanio(), 1);
    EXPECT_EQ(lista.inicio(), 10);
    EXPECT_EQ(lista.final(), 10);

    lista.agregar_inicio(20);
    EXPECT_EQ(lista.tamanio(), 2);
    EXPECT_EQ(lista.inicio(), 20);
    EXPECT_EQ(lista.final(), 10);
}

TEST_F(ListaTest, AgregarFinal) {
    lista.agregar_final(10);
    EXPECT_FALSE(lista.es_vacia());
    EXPECT_EQ(lista.tamanio(), 1);
    EXPECT_EQ(lista.inicio(), 10);
    EXPECT_EQ(lista.final(), 10);

    lista.agregar_final(20);
    EXPECT_EQ(lista.tamanio(), 2);
    EXPECT_EQ(lista.inicio(), 10);
    EXPECT_EQ(lista.final(), 20);
}

TEST_F(ListaTest, EliminarInicio) {
    lista.agregar_final(10);
    lista.agregar_final(20);
    lista.agregar_final(30);

    lista.eliminar_inicio();
    EXPECT_EQ(lista.tamanio(), 2);
    EXPECT_EQ(lista.inicio(), 20);
    EXPECT_EQ(lista.final(), 30);

    lista.eliminar_inicio();
    EXPECT_EQ(lista.tamanio(), 1);
    EXPECT_EQ(lista.inicio(), 30);

    lista.eliminar_inicio();
    EXPECT_TRUE(lista.es_vacia());
}

TEST_F(ListaTest, EliminarFinal) {
    lista.agregar_final(10);
    lista.agregar_final(20);
    lista.agregar_final(30);

    lista.eliminar_final();
    EXPECT_EQ(lista.tamanio(), 2);
    EXPECT_EQ(lista.inicio(), 10);
    EXPECT_EQ(lista.final(), 20);

    lista.eliminar_final();
    EXPECT_EQ(lista.tamanio(), 1);
    EXPECT_EQ(lista.inicio(), 10);

    lista.eliminar_final();
    EXPECT_TRUE(lista.es_vacia());
}

TEST_F(ListaTest, OperacionesEnListaVaciaLanzanExcepcion) {
    EXPECT_THROW(lista.inicio(), std::runtime_error);
    EXPECT_THROW(lista.final(), std::runtime_error);
    EXPECT_THROW(lista.eliminar_inicio(), std::runtime_error);
    EXPECT_THROW(lista.eliminar_final(), std::runtime_error);
}

TEST_F(ListaTest, MezclaDeOperaciones) {
    lista.agregar_inicio(2);
    lista.agregar_final(3);
    lista.agregar_inicio(1); // Lista: 1 -> 2 -> 3
    EXPECT_EQ(lista.tamanio(), 3);
    EXPECT_EQ(lista.inicio(), 1);
    EXPECT_EQ(lista.final(), 3);

    lista.eliminar_final(); // Lista: 1 -> 2
    EXPECT_EQ(lista.tamanio(), 2);
    EXPECT_EQ(lista.final(), 2);

    lista.eliminar_inicio(); // Lista: 2
    EXPECT_EQ(lista.tamanio(), 1);
    EXPECT_EQ(lista.inicio(), 2);
}