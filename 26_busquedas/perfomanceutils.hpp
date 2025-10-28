#ifndef PERFORMANCE_UTILS_H
#define PERFORMANCE_UTILS_H

#include <chrono>
#include <iostream>
#include <string>

class Timer {
public:
  Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

  void reset() {
    start_time = std::chrono::high_resolution_clock::now();
  }

  double elapsed_milliseconds() const {
    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1e6;
  }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

void print_metrics(const std::string& name, double time_ms, long long ops_count = -1) {
  std::cout << "\n--- Metricas para " << name << " ---" << std::endl;
  std::cout << "Tiempo de ejecucion: " << time_ms << " ms" << std::endl;
  if (ops_count != -1) {
    std::cout << "Conteo de operaciones/iteraciones: " << ops_count << std::endl;
  }
  std::cout << "------------------------------------" << std::endl;
}

#endif