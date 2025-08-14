#include <iostream>
#include "Persona.h"
#include "Estudiante.h"

int main() {
    Persona p {33, "pp"};
    p.mostrar();

    Estudiante e (22);
    e.mostrarEstudiante();

    Persona p1 = e;
    p1.mostrar();
    //p1.mostrarEstudiante();

    return 0;
}
