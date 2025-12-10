/**
 * @file main.cpp
 * @brief Ejercicio de repaso: Sistema de inventario para videojuego con enum y herencia
 * @details Implementa un sistema de items con enum, clase base y clases derivadas
 * @author Roberto Pablo Gomez
 */

#include <iostream>

/**
 * @enum TipoItem
 * @brief Enum que representa los tipos de items disponibles
 */
enum class TipoItem {
    Arma,
    Armadura,
    Pocion,
    Gema  ///< Tipo gema
};

/**
 * @brief Convierte un TipoItem a su representación en string
 * @param tipoItem Tipo de item a convertir
 * @return String con el nombre del tipo de item
 */
std::string tipoItemToString (TipoItem tipoItem) {
    switch (tipoItem) {
        case TipoItem::Arma:
            return "Arma";
        case TipoItem::Armadura:
            return "Armadura";
        case TipoItem::Pocion:
            return "Pocion";
        case TipoItem::Gema:
            return "Gema";
        default:
            return "Tipo de item desconocido";
    }
}

/**
 * @class Item
 * @brief Clase base que representa un item del inventario
 */
class Item {
protected:
    std::string nombre;  ///< Nombre del item
    double precio;       ///< Precio del item
    TipoItem tipo;       ///< Tipo del item

public:
    /**
     * @brief Constructor de Item
     * @param nombre Nombre del item
     * @param precio Precio del item
     * @param tipo Tipo del item
     */
    Item(const std::string& nombre, double precio, TipoItem tipo) : nombre(nombre), precio(precio), tipo(tipo) {}
    /**
     * @brief Destructor virtual
     */
    virtual ~Item() {}

    /**
     * @brief Método virtual que muestra la información del item
     */
    virtual void mostrarInformacion() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Precio: " << precio << std::endl;
// Como hacemos para mostrar el nombre del valor del enumerado ? 
        std::cout << "Tipo item: " << static_cast<int>(tipo) << std::endl;
        std::cout << "Tipo item: " << tipoItemToString(tipo) << std::endl;
    }
};

/**
 * @class Arma
 * @brief Clase que representa un arma, hereda de Item
 */
class Arma : public Item {
    int danio;  ///< Daño que causa el arma
public:
    /**
     * @brief Constructor de Arma
     * @param nombre Nombre del arma
     * @param precio Precio del arma
     * @param danio Daño del arma
     */
    Arma(const std::string& nombre, double precio, int danio) : Item(nombre, precio, TipoItem::Arma), danio(danio) {}
    /**
     * @brief Sobrescribe mostrarInformacion para incluir el daño
     */
    void mostrarInformacion() override {
        // Como hacemos para mostrar también los datos de los campos de la superclase? 
        Item::mostrarInformacion();
        std::cout << "Danio: " << danio << std::endl;
    }
};

/**
 * @class Pocion
 * @brief Clase que representa una poción, hereda de Item
 */
class Pocion : public Item {
    int curacion;  ///< Cantidad de curación de la poción
public:
    /**
     * @brief Constructor de Pocion
     * @param nombre Nombre de la poción
     * @param precio Precio de la poción
     * @param curacion Cantidad de curación
     */
    Pocion(const std::string& nombre, double precio, int curacion) : Item(nombre, precio, TipoItem::Pocion), curacion(curacion) {}
    /**
     * @brief Sobrescribe mostrarInformacion para incluir la curación
     */
    void mostrarInformacion() override {
        // Como hacemos para mostrar también los datos de los campos de la superclase? 
        Item::mostrarInformacion();
        std::cout << "Curacion: " << curacion << std::endl;
    }
};

/**
 * @brief Función principal que demuestra el polimorfismo
 * @return 0 si el programa termina correctamente
 */
int main() {
    Item *i1 = new Item("nombre", 1.23, TipoItem::Gema);
    Item *i2 = new Arma("elArma", 10000, 10);
    Item *i3 = new Pocion("laPocion", 10000000, 20);

    i1->mostrarInformacion();
    std::cout << std::endl;
    std::cout << std::endl;
    i3->mostrarInformacion();

    return 0;
}
