/**
 * @file main.cpp
 * @brief Programa principal que compara búsqueda lineal vs búsqueda binaria
 * @author Roberto Pablo Gomez
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

#include "perfomanceutils.hpp"

/**
 * @brief Realiza una búsqueda lineal en un vector
 * @param data Vector donde buscar
 * @param value Valor a buscar
 * @param comparisons Contador de comparaciones realizadas
 * @return true si se encuentra el valor, false en caso contrario
 */
bool linear_search(const std::vector<int>& data, int value, long long& comparisons) {
    comparisons = 0;
    for (int x : data) {
        comparisons++;
        if (x == value) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Realiza una búsqueda binaria en un vector ordenado
 * @param data Vector ordenado donde buscar
 * @param value Valor a buscar
 * @param comparisons Contador de comparaciones realizadas
 * @return true si se encuentra el valor, false en caso contrario
 */
bool binary_search_custom(const std::vector<int>& data, int value, long long& comparisons) {
    comparisons = 0;
    int low = 0;
    int high = data.size() - 1;

    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;

        if (data[mid] == value) {
          return true;
        }

        if (data[mid] < value) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
    }
    return false;
}

int main() {
    const int NUM_ELEMENTOS = 10000000;
    std::vector<int> datos(NUM_ELEMENTOS);
    std::iota(datos.begin(), datos.end(), 0);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(datos.begin(), datos.end(), g);

    int valor_a_buscar_existente = NUM_ELEMENTOS / 2;
    int valor_a_buscar_no_existente = NUM_ELEMENTOS + 100;

    long long comparisons = 0;
    Timer timer;

    std::cout << "--- Pruebas de Busqueda Lineal ---" << std::endl;

    timer.reset();
    bool found_linear = linear_search(datos, valor_a_buscar_existente, comparisons);
    print_metrics("Busqueda Lineal (Existente)", timer.elapsed_milliseconds(), comparisons);
    std::cout << "Valor " << valor_a_buscar_existente << (found_linear ? " encontrado" : " NO encontrado") << std::endl;

    timer.reset();
    found_linear = linear_search(datos, valor_a_buscar_no_existente, comparisons);
    print_metrics("Busqueda Lineal (No Existente)", timer.elapsed_milliseconds(), comparisons);
    std::cout << "Valor " << valor_a_buscar_no_existente << (found_linear ? " encontrado" : " NO encontrado") << std::endl;

    std::cout << "\n--- Pruebas de Busqueda Binaria ---" << std::endl;

    std::sort(datos.begin(), datos.end());
    std::cout << "Datos ordenados para busqueda binaria." << std::endl;

    timer.reset();
    bool found_binary = binary_search_custom(datos, valor_a_buscar_existente, comparisons);
    print_metrics("Busqueda Binaria (Existente)", timer.elapsed_milliseconds(), comparisons);
    std::cout << "Valor " << valor_a_buscar_existente << (found_binary ? " encontrado" : " NO encontrado") << std::endl;

    timer.reset();
    found_binary = binary_search_custom(datos, valor_a_buscar_no_existente, comparisons);
    print_metrics("Busqueda Binaria (No Existente)", timer.elapsed_milliseconds(), comparisons);
    std::cout << "Valor " << valor_a_buscar_no_existente << (found_binary ? " encontrado" : " NO encontrado") << std::endl;

    return 0;
}