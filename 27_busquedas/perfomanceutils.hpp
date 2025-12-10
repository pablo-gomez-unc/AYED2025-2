/**
 * @file perfomanceutils.hpp
 * @brief Utilidades para medir el rendimiento de algoritmos
 * @author Roberto Pablo Gomez
 */

#ifndef PERFORMANCE_UTILS_H
#define PERFORMANCE_UTILS_H

#include <chrono>
#include <iostream>
#include <string>

/**
 * @class Timer
 * @brief Clase para medir el tiempo de ejecución
 */
class Timer {
public:
  /**
   * @brief Constructor que inicia el temporizador
   */
  Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

  /**
   * @brief Reinicia el temporizador
   */
  void reset() {
    start_time = std::chrono::high_resolution_clock::now();
  }

  /**
   * @brief Obtiene el tiempo transcurrido en milisegundos
   * @return Tiempo transcurrido en milisegundos
   */
  double elapsed_milliseconds() const {
    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1e6;
  }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;  ///< Tiempo de inicio
};

/**
 * @brief Imprime métricas de rendimiento
 * @param name Nombre de la operación
 * @param time_ms Tiempo de ejecución en milisegundos
 * @param ops_count Número de operaciones (opcional)
 */
void print_metrics(const std::string& name, double time_ms, long long ops_count = -1) {
  std::cout << "\n--- Metricas para " << name << " ---" << std::endl;
  std::cout << "Tiempo de ejecucion: " << time_ms << " ms" << std::endl;
  if (ops_count != -1) {
    std::cout << "Conteo de operaciones/iteraciones: " << ops_count << std::endl;
  }
  std::cout << "------------------------------------" << std::endl;
}

#endif