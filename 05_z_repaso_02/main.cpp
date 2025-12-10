/**
 * @file main.cpp
 * @brief Ejercicio de repaso: Sistema de gestión de empleados con punteros
 * @details Implementa una estructura Empleado con métodos que usan punteros
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include <string>

/**
 * @struct Empleado
 * @brief Estructura que representa un empleado con nombre, ID y salario
 */
struct Empleado {
    std::string nombre;  ///< Nombre del empleado
    int id;              ///< ID del empleado
    /**
     * @brief Obtiene un puntero al salario del empleado
     * @return Puntero al salario
     */
    double* getPtrSalario () {
        return &salario;
    };
    /**
     * @brief Imprime los datos del empleado
     */
    void printDatos () {
        std::cout << "Empleado id: "    << id 
                  << " nombre: "        << nombre 
                  << " salario: "       << salario << std::endl;
    }
    /**
     * @brief Constructor de Empleado
     * @param nombre Nombre del empleado
     * @param id ID del empleado
     * @param salario Salario del empleado
     */
    Empleado (std::string nombre, int id, double salario) : nombre(nombre), id(id), salario(salario) {};
private:
    double salario;  ///< Salario del empleado (privado)
};

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    Empleado e1 = Empleado("el mejor empleado", 1, 1000);
    e1.printDatos();
    double* salario = e1.getPtrSalario();
    *salario = 10000000;
    e1.printDatos();
    return 0;
}
