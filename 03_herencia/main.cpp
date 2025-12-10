/**
 * @file main.cpp
 * @brief Programa principal que demuestra el uso de herencia
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include "Persona.h"
#include "Estudiante.h"

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    Persona p {33, "pp"};
    p.mostrar();

    Estudiante e (22);
    e.mostrarEstudiante();

    Persona p1 = e;
    p1.mostrar();
    //p1.mostrarEstudiante();

    return 0;
}
