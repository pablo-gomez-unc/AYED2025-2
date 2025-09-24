#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <random>

// Simula un sistema de compra en línea utilizando una pila y una cola.
// Pila de "Deshacer" (Pila de Acciones): Cuando un usuario agrega un artículo al carrito, la acción se "empuja" en una pila.
// Si el usuario hace clic en "Deshacer", la última acción se "desapila" y el artículo se elimina del carrito.
// Cola de "Rehacer" (Cola de Acciones Deshechas): Si el usuario hace clic en "Rehacer" (después de un "Deshacer"),
// la acción se mueve de una cola de "Rehacer" a la pila principal.
// Mantén un límite para la cantidad de acciones que se pueden "deshacer" para evitar un consumo excesivo de memoria.
struct Producto
{
    int precio;
    std::string identificador;
};

class Carrito
{
    std::vector<Producto> productos; // Vector para almacenar los productos en el carrito
    int total;                       // Total de productos en el carrito

public:
    std::queue<Producto> rehacer_producto;  // Cola para acciones de rehacer
    std::stack<Producto> deshacer_producto; // Pila para acciones de deshacer

    // Constructor que inicializa el carrito teniendo un total de productos
    Carrito(int t) : total(t)
    {
        productos.reserve(t);
        productos.clear();

        // Por cada producto, se genera un precio aleatorio y un identificador
        for (int i = 0; i < t; i++)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(50, 1000);

            Producto p = {dist(gen), "Producto_" + std::to_string(i)};

            productos.push_back(p);
        }
    }

    void empujar(int index)
    {
        if (index < 0 || index > total)
        {
            std::cout << "Índice fuera de rango. El indice tiene que estar entre 0 y " << total - 1 << std::endl;
            return;
        }

        deshacer_producto.push(productos[index]);
        std::cout << "Producto agregado al carrito: " << productos[index].identificador << " - Precio: " << productos[index].precio << std::endl;
    }

    void deshacer()
    {
        if (deshacer_producto.empty())
        {
            std::cout << "No hay acciones para deshacer." << std::endl;
            return;
        }

        Producto tmp = deshacer_producto.top();
        deshacer_producto.pop();
        rehacer_producto.push(tmp);

        // Limitar la cola de rehacer a 5 elementos
        if (rehacer_producto.size() > 5)
        {
            rehacer_producto.pop();
        }
    }

    void rehacer()
    {
        if (rehacer_producto.empty())
        {
            std::cout << "No hay acciones para rehacer." << std::endl;
            return;
        }

        Producto tmp = rehacer_producto.front();
        rehacer_producto.pop();
        deshacer_producto.push(tmp);
    }

    void print()
    {
        std::cout << "Productos disponibles:" << std::endl;
        for (size_t i = 0; i < productos.size(); i++)
        {
            std::cout << "[" << i << "] " << productos[i].identificador
                      << " - Precio: " << productos[i].precio << std::endl;
        }

        std::cout << std::endl
                  << "Pila de Deshacer:" << std::endl;
        if (deshacer_producto.empty())
        {
            std::cout << "No hay acciones para deshacer" << std::endl;
        }
        else
        {
            std::stack<Producto> temp = deshacer_producto;
            int pos = temp.size();
            while (!temp.empty())
            {
                std::cout << "[" << pos - 1 << "] " << temp.top().identificador
                          << " - Precio: " << temp.top().precio << std::endl;
                temp.pop();
                pos--;
            }
        }

        std::cout << std::endl
                  << "Cola de Rehacer:" << std::endl;
        if (rehacer_producto.empty())
        {
            std::cout << "No hay acciones para rehacer" << std::endl;
        }
        else
        {
            std::queue<Producto> temp = rehacer_producto;
            int pos = 0;
            while (!temp.empty())
            {
                std::cout << "[" << pos << "] " << temp.front().identificador
                          << " - Precio: " << temp.front().precio << std::endl;
                temp.pop();
                pos++;
            }
        }

        std::cout << "----------------------------------------" << std::endl;
    }
};

// queue , push , pop
// stack , push , pop
int main()
{
    Carrito carrito(10);
    carrito.print();

    std::cout << "Agregando 3 productos al carrito..." << std::endl;
    carrito.empujar(2);
    carrito.empujar(5);
    carrito.empujar(7);
    carrito.print();

    std::cout << "Deshaciendo 1 accion..." << std::endl;
    carrito.deshacer();
    carrito.print();

    std::cout << "Rehaciendo 1 accion..." << std::endl;
    carrito.rehacer();
    carrito.print();

    std::cout << "Deshaciendo 2 acciones..." << std::endl;
    carrito.deshacer();
    carrito.deshacer();
    carrito.print();

    std::cout << "Rehaciendo 2 acciones..." << std::endl;
    carrito.rehacer();
    carrito.rehacer();
    carrito.print();

    return 0;
}
