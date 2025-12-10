/**
 * @file main.cpp
 * @brief Programa principal que demuestra el uso de std::vector
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    std::vector<std::string> lista;
    lista.push_back("dato1");
    lista.push_back("dato2");
    lista.push_back("dato3");

    for (const auto& elemento : lista) {
        std::cout << elemento << std::endl;
    }

    std::cout << lista.size() << std::endl;
    std::cout << lista[2] << std::endl;

    lista.pop_back();

    std::cout << lista.size() << std::endl;
    std::cout << lista[1] << std::endl;

    lista.pop_back();
    std::cout << lista.size() << std::endl;
    std::cout << lista[2] << std::endl;

    return 0;
}
