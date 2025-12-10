/**
 * @file Forma.hpp
 * @brief Definición de la clase base Forma con método virtual
 * @author Roberto Pablo Gomez
 * @date 20/03/2025
 */

#ifndef VIRTUAL_FORMA_H
#define VIRTUAL_FORMA_H

#include <iostream>

/**
 * @class Forma
 * @brief Clase base abstracta que representa una forma geométrica
 */
class Forma {
public:
    /**
     * @brief Método virtual para dibujar la forma
     */
    virtual void dibujar () const;
};


#endif //VIRTUAL_FORMA_H
