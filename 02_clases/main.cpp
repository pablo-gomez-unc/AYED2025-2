/**
 * @file main.cpp
 * @brief Programa que demuestra el uso de clases en C++
 * @author Roberto Pablo Gomez
 */

#include <iostream>

/**
 * @class Persona
 * @brief Clase que representa una persona con edad y nombre públicos
 */
class Persona {
public:
    /**
     * @brief Constructor por defecto
     */
    Persona(): edad(0), nombre(std::string("hola")) {};
    int edad;            ///< Edad de la persona
    std::string nombre; ///< Nombre de la persona
};

/**
 * @class PersonaConst
 * @brief Clase que representa una persona con miembros privados
 */
class PersonaConst {
public:
    /**
     * @brief Constructor por defecto
     */
    PersonaConst(): edad(0), nombre(std::string("")) {};
    /**
     * @brief Constructor con parámetros
     * @param e Edad de la persona
     * @param n Nombre de la persona
     */
    PersonaConst(int e, std::string n): edad(e), nombre(n) {};
    /**
     * @brief Muestra la información de la persona
     */
    void mostrar() {
      std::cout << edad << "  " << nombre << std::endl;
    };
private:
    int edad;            ///< Edad de la persona
    std::string nombre;  ///< Nombre de la persona
};

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    Persona p;
    std::cout << p.edad << std::endl;
    std::cout << p.nombre << std::endl;
    Persona p1 = Persona();

    Persona *p2 = new Persona();
    std::cout << p2->edad << std::endl;
    std::cout << p2->nombre << std::endl;
    std::cout << (*p2).edad << std::endl;
    std::cout << (*p2).nombre << std::endl;
    delete p2;

    PersonaConst pc = PersonaConst(22, "pepe");
    pc.mostrar();

    PersonaConst *pc1 = new PersonaConst(22, "pepe");
    pc1->mostrar();
    delete pc1;

    PersonaConst pi;
    PersonaConst pi1(22, std::string ("aa"));
    PersonaConst pi2{22, "jj"};

    return 0;
}