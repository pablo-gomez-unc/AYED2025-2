/**
 * @file test_herencia.cpp
 * @brief Tests unitarios para las clases Persona y Estudiante
 * @author Roberto Pablo Gomez
 */

#include <gtest/gtest.h>
#include "../Persona.h"
#include "../Estudiante.h"

/**
 * @brief Test para verificar el constructor de Persona con parámetros
 */
TEST(PersonaTest, ConstructorWithParameters) {
    Persona p(25, "Juan");
    SUCCEED();
}

/**
 * @brief Test para verificar el constructor de Estudiante
 */
TEST(EstudianteTest, ConstructorTest) {
    Estudiante e(12345);
    SUCCEED();
}
