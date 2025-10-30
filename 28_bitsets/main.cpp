#include <iostream>
#include <bitset>

const int NUM_ASIENTOS = 100;
std::bitset<NUM_ASIENTOS> asientosDisponibilidad;

void imprimirEstadoAsientos(int inicio, int fin) {
    std::cout << "Estado de asientos del " << inicio << " al " << fin << ":" << std::endl;
    for (int i = inicio; i <= fin; ++i) {
        if (i >= 0 && i < NUM_ASIENTOS) {
            std::cout << "  Asiento " << i << ": " << (asientosDisponibilidad.test(i) ? "OCUPADO" : "DISPONIBLE") << std::endl;
        }
    }
}

int main() {
    bool asientosarray[NUM_ASIENTOS] = {};
    asientosarray[0] = true;
    asientosarray[NUM_ASIENTOS-1] = true;

    asientosDisponibilidad.reset();
    asientosDisponibilidad.set(0);
    asientosDisponibilidad.set(99);

    for (int i = 0; i < NUM_ASIENTOS; i += 2) {
        asientosDisponibilidad.set(i);
    }

    bool estado = asientosDisponibilidad.test(50);
    std::cout << "Estado del asiento 50: " << (estado ? "OCUPADO" : "DISPONIBLE") << std::endl;

    long long ocupados = asientosDisponibilidad.count();
    std::cout << "Total de asientos ocupados: " << ocupados << std::endl;

    int primer_disponible = -1;
    for (int i = 0; i < NUM_ASIENTOS; ++i) {
        if (!asientosDisponibilidad.test(i)) {
            primer_disponible = i;
            break;
        }
    }
    if (primer_disponible != -1) {
        std::cout << "Primer asiento disponible: " << primer_disponible << std::endl;
    } else {
        std::cout << "No hay asientos disponibles." << std::endl;
    }

    imprimirEstadoAsientos(0, 20);

    return 0;
}