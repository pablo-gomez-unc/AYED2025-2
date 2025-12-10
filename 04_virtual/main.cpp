/**
 * @file main.cpp
 * @brief Programa principal que demuestra el uso de métodos virtuales
 * @author Roberto Pablo Gomez
 */

#include "Forma.hpp"
#include "Circulo.hpp"

/**
 * @brief Función que dibuja una forma usando polimorfismo
 * @param f Referencia constante a una Forma
 */
void dibujarForma (const Forma& f) {
    f.dibujar();
}

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    Forma f;
    //f.dibujar();
    Circulo c;
    //c.dibujar();

    dibujarForma(f);
    dibujarForma(c);
    return 0;
}
