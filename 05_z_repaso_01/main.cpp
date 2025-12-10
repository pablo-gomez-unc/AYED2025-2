/**
 * @file main.cpp
 * @brief Ejercicio de repaso: Sistema de habilidades para un videojuego RPG
 * @details Implementa una clase base abstracta Habilidad con métodos virtuales puros
 * y dos clases derivadas que demuestran polimorfismo
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Habilidad
 * @brief Clase base abstracta que representa una habilidad en el juego
 */
class Habilidad
{
    string nombre;  ///< Nombre de la habilidad

public:
    /**
     * @brief Constructor de Habilidad
     * @param nombre Nombre de la habilidad
     */
    Habilidad(const string &nombre)
    {
        this->nombre = nombre;
    };
    /**
     * @brief Método virtual puro para activar la habilidad
     */
    virtual void activar() const = 0;
    /**
     * @brief Destructor virtual
     */
    virtual ~Habilidad () {};
};

/**
 * @class HechizoDeFuego
 * @brief Clase que representa un hechizo de fuego
 */
class HechizoDeFuego : public Habilidad
{
public:
    /**
     * @brief Constructor de HechizoDeFuego
     */
    HechizoDeFuego() : Habilidad("Hechizo de Fuego") {};
    /**
     * @brief Implementa la activación del hechizo de fuego
     */
    void activar() const override
    {
        cout << "Lanzas una bola de fuego, ¡quemando al enemigo!" << endl;
    };
    /**
     * @brief Destructor de HechizoDeFuego
     */
    ~HechizoDeFuego () {cout << "Destructor Hechizo de fuego"<< endl; };
};

/**
 * @class AtaqueFisico
 * @brief Clase que representa un ataque físico
 */
class AtaqueFisico : public Habilidad
{
public:
    /**
     * @brief Constructor de AtaqueFisico
     */
    AtaqueFisico() : Habilidad("Ataque Fisico") {};
    /**
     * @brief Implementa la activación del ataque físico
     */
    void activar() const override
    {
        cout << "Asestas un golpe contundente con tu espada, ¡dañando al enemigo!" << endl;
    };
    /**
     * @brief Destructor de AtaqueFisico
     */
    ~AtaqueFisico () {cout << "Destructor Ataque Fisico"<< endl; };
};

/**
 * @brief Función principal que demuestra el polimorfismo
 * @return 0 si el programa termina correctamente
 */
int main()
{
    Habilidad* h1 = new HechizoDeFuego();
    Habilidad* h2 = new AtaqueFisico(); 
    h1->activar();
    h2->activar();
    delete h1;
    delete h2;
    return 0;
}
