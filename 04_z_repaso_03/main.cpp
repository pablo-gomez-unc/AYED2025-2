// Estás trabajando en un videojuego de aventura y necesitas un sistema de inventario que pueda manejar diferentes 
// tipos de objetos. Para asegurar que los datos estén bien organizados y evitar errores, usarás un enum para 
// clasificar los ítems. Tu tarea es:
// Crear una enum llamada TipoItem que defina las siguientes categorías de ítems: Arma, Armadura, Pocion, y Gema. 💎
// Crear una clase base llamada Item que contenga un nombre (std::string), un precio (double), y el TipoItem del 
// objeto.
// Implementar dos clases hijas que hereden de Item:
// - Arma: Un arma tiene un daño (int). Su constructor debe inicializar el tipo de ítem a TipoItem::Arma.
// - Pocion: Una poción tiene una cantidad de curación (int). Su constructor debe inicializar el tipo de ítem a
// TipoItem::Pocion.
// Crea un método virtual en la clase base Item llamado mostrarInformacion() que imprima los datos básicos del 
// ítem (nombre, precio y tipo).
// Sobrescribe este método en las clases hijas para que impriman su información específica (el daño en Arma o 
// la curación en Pocion) además de la información básica.
// En main, utiliza punteros a la clase base para instanciar objetos de las clases derivadas y luego llama 
// al método mostrarInformacion() a través de los punteros para demostrar el polimorfismo.
#include <iostream>

enum class TipoItem {
    Arma,
    Armadura,
    Pocion,
    Gema
};

class Item {
protected:
    std::string nombre;
    double precio;
    TipoItem tipo;

public:
    Item(const std::string& nombre, double precio, TipoItem tipo) : nombre(nombre), precio(precio), tipo(tipo) {}
    virtual ~Item() {}

    virtual void mostrarInformacion() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Precio: " << precio << std::endl;
        std::cout << "Tipo item: " << static_cast<int>(tipo) << std::endl;
    }
};

class Arma : public Item {
    int danio;
public:
    Arma(const std::string& nombre, double precio, int danio) : Item(nombre, precio, TipoItem::Arma), danio(danio) {}
    void mostrarInformacion() override {
        std::cout << "Danio: " << danio << std::endl;
    }
};

class Pocion : public Item {
    int curacion;
public:
    Pocion(const std::string& nombre, double precio, int curacion) : Item(nombre, precio, TipoItem::Pocion), curacion(curacion) {}
    void mostrarInformacion() override {
        // 
        std::cout << "Curacion: " << curacion << std::endl;
    }
};

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
