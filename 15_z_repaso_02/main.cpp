#include <iostream>
#include <string>
#include <queue>
#include <stack>


// Simula un sistema de compra en línea utilizando una pila y una cola.
// Pila de "Deshacer" (Pila de Acciones): Cuando un usuario agrega un artículo al carrito, la acción se "empuja" en una pila. 
// Si el usuario hace clic en "Deshacer", la última acción se "desapila" y el artículo se elimina del carrito.
// Cola de "Rehacer" (Cola de Acciones Deshechas): Si el usuario hace clic en "Rehacer" (después de un "Deshacer"), 
// la acción se mueve de una cola de "Rehacer" a la pila principal.
// Mantén un límite para la cantidad de acciones que se pueden "deshacer" para evitar un consumo excesivo de memoria.
struct Producto {
    int precio;
    std::string identificador;
}

// queue , push , pop
// stack , push , pop
int main() {
    std::queue<Producto> rehacer;
    std::stack<Producto> deshacer;
    std::vector<Producto> carrito;

    return 0;
}   
