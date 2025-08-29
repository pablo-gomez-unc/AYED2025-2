// Eres el ingeniero de software principal en 'TechSolutions'. Tu tarea es desarrollar un módulo para gestionar 
// la información de los empleados. La empresa te ha pedido que uses punteros para optimizar el acceso a los 
// datos y la memoria. Necesitas:

// Crear una struct llamada Empleado que contenga el nombre (std::string), el ID (int) y el salario (double).
// Implementar una función que, utilizando punteros, actualice el salario de un empleado basándose en su ID. 
// Esto simula un aumento de sueldo. 💰
// Implementar una segunda función que imprima los datos de un empleado, también usando punteros.
#include <iostream>
#include <string>

struct Empleado {
    std::string nombre;
    int id;
    double* getPtrSalario () {
        return &salario;
    };
    void printDatos () {
        std::cout << "Empleado id: "    << id 
                  << " nombre: "        << nombre 
                  << " salario: "       << salario << std::endl;
    }
    Empleado (std::string nombre, int id, double salario) : nombre(nombre), id(id), salario(salario) {};
private:
    double salario;
};

int main() {
    Empleado e1 = Empleado("el mejor empleado", 1, 1000);
    e1.printDatos();
    double* salario = e1.getPtrSalario();
    *salario = 10000000;
    e1.printDatos();
    return 0;
}
