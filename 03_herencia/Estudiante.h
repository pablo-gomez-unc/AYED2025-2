/**
 * @file Estudiante.h
 * @brief Definición de la clase Estudiante que hereda de Persona
 * @author Roberto Pablo Gomez
 * @date 20/03/2025
 */

#ifndef HERENCIA_ESTUDIANTE_H
#define HERENCIA_ESTUDIANTE_H
#include "Persona.h"

/**
 * @class Estudiante
 * @brief Clase que representa un estudiante, hereda de Persona
 */
class Estudiante : public Persona {
public:
    /**
     * @brief Constructor de Estudiante
     * @param m Número de matrícula del estudiante
     */
    Estudiante (int m) : Persona() , matricula(m) {}
    /**
     * @brief Muestra la información del estudiante
     */
    void mostrarEstudiante ();
private:
    int matricula;  ///< Número de matrícula del estudiante
};


#endif //HERENCIA_ESTUDIANTE_H
