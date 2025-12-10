/**
 * @file Circulo.hpp
 * @brief Definición de la clase Circulo que hereda de Forma
 * @author Roberto Pablo Gomez
 * @date 20/03/2025
 */

#ifndef VIRTUAL_CIRCULO_H
#define VIRTUAL_CIRCULO_H

#include "Forma.hpp"

/**
 * @class Circulo
 * @brief Clase que representa un círculo, hereda de Forma
 */
class Circulo : public Forma {
public:
    /**
     * @brief Sobrescribe el método dibujar para un círculo
     */
    void dibujar () const override;
};


#endif //VIRTUAL_CIRCULO_H
