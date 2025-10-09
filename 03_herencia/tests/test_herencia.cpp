
#include <gtest/gtest.h>
#include "../Persona.h"
#include "../Estudiante.h"

TEST(PersonaTest, ConstructorWithParameters) {
    Persona p(25, "Juan");
    SUCCEED();
}

TEST(EstudianteTest, ConstructorTest) {
    Estudiante e(12345);
    SUCCEED();
}
