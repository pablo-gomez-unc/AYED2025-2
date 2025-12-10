/**
 * @file Estudiante.cpp
 * @brief Implementación de la clase Estudiante
 * @author Roberto Pablo Gomez
 * @date 20/03/2025
 */

#include <iostream>
#include "Estudiante.h"

/**
 * @brief Muestra la información del estudiante
 */
void Estudiante::mostrarEstudiante() {
    mostrar();
    std::cout << matricula << std::endl;
}

