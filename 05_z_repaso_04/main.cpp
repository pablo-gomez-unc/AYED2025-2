/**
 * @file main.cpp
 * @brief Ejercicio de repaso: Sistema de gestión de inventario con arrays de punteros
 * @details Demuestra el uso de arrays de punteros a clases base para polimorfismo
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
     * @brief Constructor por defecto
     */
    Item () : nombre(""), precio(0.0), tipo(TipoItem::Arma){};
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
 * @brief Función principal que demuestra arrays de punteros y polimorfismo
 * @return 0 si el programa termina correctamente
 */
int main() {
    const int TAMANIO = 5;
    //Item items [5]; // array de items - todo en el stack
    //Item* items [5]; // stack : items [ p1 (heap), p2 (heap),p3 (heap),p4 ,p5 ]
    Item** items = new Item*[TAMANIO]; // heap : items  [ p1 (heap), p2 (heap),p3 (heap),p4 ,p5 ]

    items[0] = new Arma("Espada de Acero", 150.0, 50);  // Heap : item 
    items[1] = new Pocion("Poción de Salud", 25.5, 20); // Heap : item 
    items[2] = new Arma("Arco y Flecha", 120.0, 40);    // Heap : item 
    items[3] = new Pocion("Poción de Mana", 30.0, 15);  // Heap : item 
    items[4] = new Pocion("Poción de Mana", 30.0, 15);  // Heap : item 

    std::cout << "--- Contenido del Inventario ---" << std::endl;
    for (int i = 0; i < TAMANIO; ++i) {
        std::cout << "\n--------------------------" << std::endl;
        items[i]->mostrarInformacion();
    }

    for (int i = 0; i < TAMANIO; ++i) {
        delete items[i];
    }
    delete[] items;

    return 0;
}
