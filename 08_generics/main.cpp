/**
 * @file main.cpp
 * @brief Programa principal que demuestra el uso de templates y genéricos
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include "lista.hpp"

/**
 * @class Contenedor
 * @brief Clase genérica que representa un contenedor
 * @tparam T Tipo de dato almacenado
 */
template<typename T>
class Contenedor {
private:
    T dato;  ///< Dato almacenado en el contenedor
public:
    /**
     * @brief Constructor por defecto
     */
    Contenedor(): dato(0) { std::cout << "number" << std::endl; };
};

/**
 * @brief Especialización de Contenedor para std::string
 */
template<>
class Contenedor<std::string> {
private:
    std::string dato;  ///< Dato almacenado en el contenedor
public:
    /**
     * @brief Constructor por defecto para strings
     */
    Contenedor(): dato("NO_INICIALIZADO") { std::cout << "string" << std::endl; };
};

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    std::cout << "Generics 2025" << std::endl;
    Contenedor<int> ci;
    Contenedor<float> cf;
    Contenedor<std::string> cs;

    auto *l = new Lista<int>();
    l->agregar(1);
    l->agregar(2);
    l->imprimir();
    delete l;

    auto *l1 = new Lista<std::string>();
    l1->agregar("hola");
    l1->agregar("chau");
    l1->imprimir();
    delete l1;

    return 0;
}
