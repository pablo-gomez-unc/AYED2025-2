#include "Forma.hpp"
#include "Circulo.hpp"

void dibujarForma (const Forma& f) {
    f.dibujar();
}

int main() {
    Forma f;
    //f.dibujar();
    Circulo c;
    //c.dibujar();

    dibujarForma(f);
    dibujarForma(c);
    return 0;
}
