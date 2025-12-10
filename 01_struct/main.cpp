/**
 * @file main.cpp
 * @brief Programa que demuestra el uso de estructuras en C++
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include <string>

/**
 * @struct Item
 * @brief Estructura que representa un item con nombre y cantidad
 */
struct Item {
  std::string m_nombre;  ///< Nombre del item
  int m_cantidad;        ///< Cantidad del item
};

/**
 * @struct Persona
 * @brief Estructura que representa una persona con edad y nombre
 */
struct Persona {
    int edad;            ///< Edad de la persona
    std::string nombre;  ///< Nombre de la persona
};

/**
 * @struct PersonaConst
 * @brief Estructura que representa una persona con constructores personalizados
 */
struct PersonaConst {
    int edad;            ///< Edad de la persona
    std::string nombre;  ///< Nombre de la persona

    PersonaConst() = delete;
    /**
     * @brief Constructor que inicializa solo el nombre
     * @param n Nombre de la persona
     */
    PersonaConst(const std::string& n) {
        edad = 0;
        nombre = n;
    };
    /**
     * @brief Constructor que inicializa edad y nombre
     * @param e Edad de la persona
     * @param n Nombre de la persona
     */
    PersonaConst(int e, std::string n) : edad(e), nombre(n) {};

    PersonaConst(const PersonaConst&) = delete;
    PersonaConst& operator=(const PersonaConst&) = delete;
};

/**
 * @brief Función que gestiona un inventario de items
 */
void inventario ();

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    Persona p;
    std::cout << p.edad << std::endl;
    std::cout << p.nombre << std::endl;

    Persona p1 = Persona();
    std::cout << p1.edad << std::endl;
    std::cout << p1.nombre << std::endl;

    p1.edad = 22;
    p1.nombre = "pepe";

    Persona p2 = p1;

    p1.edad = 33;
    p1.nombre = "juan";

    Persona p3;
    p3 = p1;

    // PersonaConst pc;
    PersonaConst pc = PersonaConst(11, "hola");
    PersonaConst pc1 = PersonaConst("hola");
    // PersonaConst pc3;
    // pc = pc1;
    // PersonaConst pc2 = pc1;
}

/**
 * @brief Función que gestiona un inventario de items
 * Permite al usuario ingresar items y luego los muestra
 */
void inventario () {
    int numeroItems;
    std::cout << "Cantidad:" << std::endl;
    std::cin >> numeroItems;

    Item *inventario = new Item[numeroItems];

    for (int i = 0; i < numeroItems; i++) {
        std::cout << "Ingrese Nombre" << std::endl;
        std::cin >> inventario[i].m_nombre;
        std::cout << "Ingrese Cantidad" << std::endl;
        std::cin >> inventario[i].m_cantidad;
    }

    for (int i = 0; i < numeroItems; i++) {
        std::cout << inventario[i].m_nombre << std::endl;
        std::cout << inventario[i].m_cantidad << std::endl;
    }

    for (int i = 0; i < numeroItems; i++) {
        std::cout << (*(inventario+i)).m_nombre << std::endl;
        std::cout << (*(inventario+i)).m_cantidad << std::endl;
    }

    for (int i = 0; i < numeroItems; i++) {
        std::cout << (inventario+i)->m_nombre << std::endl;
        std::cout << (inventario+i)->m_cantidad << std::endl;
    }

    delete[] inventario;
}