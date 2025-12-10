/**
 * @file Persona.h
 * @brief Definición de la clase Persona
 * @author Roberto Pablo Gomez
 * @date 20/03/2025
 */

#ifndef HERENCIA_PERSONA_H
#define HERENCIA_PERSONA_H

/**
 * @class Persona
 * @brief Clase base que representa una persona
 */
class Persona {
public:
    /**
     * @brief Constructor por defecto
     */
    Persona(): edad(0), nombre(std::string("")) {};
    /**
     * @brief Constructor con parámetros
     * @param e Edad de la persona
     * @param n Nombre de la persona
     */
    Persona(int e, std::string n): edad(e), nombre(n) {};
    /**
     * @brief Muestra la información de la persona
     */
    void mostrar();
    /**
     * @brief Método de ejemplo
     */
    void metodo();
private:
    int edad;            ///< Edad de la persona
    std::string nombre;  ///< Nombre de la persona
};

#endif //HERENCIA_PERSONA_H
