//
// Created by Roberto Pablo Gomez on 20/03/2025.
//

#ifndef HERENCIA_ESTUDIANTE_H
#define HERENCIA_ESTUDIANTE_H
#include "Persona.h"

class Estudiante : public Persona {
public:
    Estudiante (int m) : Persona() , matricula(m) {}
    void mostrarEstudiante ();
private:
    int matricula;
};


#endif //HERENCIA_ESTUDIANTE_H
