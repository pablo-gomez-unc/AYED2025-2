#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

#include "perfomanceutils.hpp"

int main () {
    const int NUM_ELEMENTOS = 10000000;
    std::vector<int> claves(NUM_ELEMENTOS);
    std::iota(claves.begin(), claves.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(claves.begin(), claves.end(), g);

    std::map<int, std::string> mi_map;
    Timer timer;
    long long operations_count = 0;

    operations_count = 0;
    timer.reset();
    for (int i = 0; i < NUM_ELEMENTOS; ++i) {
        mi_map[claves[i]] = "valor_" + std::to_string(claves[i]);
        operations_count++;
    }
    print_metrics("Insercion en std::map", timer.elapsed_milliseconds(), operations_count);

    operations_count = 0;
    timer.reset();
    int valor_a_buscar = claves[NUM_ELEMENTOS / 2];
    auto it = mi_map.find(valor_a_buscar);
    if (it != mi_map.end()) {
        std::cout << "Valor " << it->second << " encontrado para clave " << it->first << std::endl;
    } else {
        std::cout << "Clave " << valor_a_buscar << " no encontrada." << std::endl;
    }
    print_metrics("Busqueda en std::map", timer.elapsed_milliseconds());

    int count = 0;
    for (const auto& pair : mi_map) {
        if (count++ >= 10) break;
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
    }

    std::unordered_map<int, std::string> mi_unordered_map;
    operations_count = 0;
    timer.reset();
    for (int i = 0; i < NUM_ELEMENTOS; ++i) {
        mi_unordered_map[claves[i]] = "valor_" + std::to_string(claves[i]);
        operations_count++;
    }
    print_metrics("Insercion en std::unordered_map", timer.elapsed_milliseconds(), operations_count);

    operations_count = 0;
    timer.reset();
    auto it2 = mi_unordered_map.find(valor_a_buscar);
    if (it2 != mi_unordered_map.end()) {
        std::cout << "Valor '" << it->second << "' encontrado para clave " << it->first << std::endl;
    } else {
        std::cout << "Clave " << valor_a_buscar << " no encontrada." << std::endl;
    }
    print_metrics("Busqueda en std::unordered_map", timer.elapsed_milliseconds());

    count = 0;
    for (const auto& pair : mi_unordered_map) {
        if (count++ >= 10) break;
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}

