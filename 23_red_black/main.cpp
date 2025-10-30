#include <iostream>

enum Color { ROJO, NEGRO };

template <typename T>
struct Nodo {
    T dato;
    Color color;
    Nodo<T>* padre;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;

    Nodo(T valor) : dato(valor), color(ROJO), padre(nullptr), izquierda(nullptr), derecha(nullptr) {}
    Nodo(Color c) : color(c), padre(nullptr), izquierda(nullptr), derecha(nullptr) {}

    bool es_nulo() const {
        return this == nullptr;
    }
};

template <typename T>
class ArbolRojoNegro {
private:
    Nodo<T>* raiz;
    Nodo<T>* NODO_NULO;

    void rotar_izquierda(Nodo<T>* x) {
        Nodo<T>* y = x->derecha;
        x->derecha = y->izquierda;

        if (y->izquierda != NODO_NULO) {
            y->izquierda->padre = x;
        }
        y->padre = x->padre;

        if (x->padre == NODO_NULO) {
            raiz = y;
        } else if (x == x->padre->izquierda) {
            x->padre->izquierda = y;
        } else {
            x->padre->derecha = y;
        }
        y->izquierda = x;
        x->padre = y;
    }

    void rotar_derecha(Nodo<T>* y) {
        Nodo<T>* x = y->izquierda;
        y->izquierda = x->derecha;

        if (x->derecha != NODO_NULO) {
            x->derecha->padre = y;
        }
        x->padre = y->padre;

        if (y->padre == NODO_NULO) {
            raiz = x;
        } else if (y == y->padre->derecha) {
            y->padre->derecha = x;
        } else {
            y->padre->izquierda = x;
        }
        x->derecha = y;
        y->padre = x;
    }

    void arreglar_insercion(Nodo<T>* k) {
        Nodo<T>* u;
        while (k->padre->color == ROJO) {
            if (k->padre == k->padre->padre->izquierda) {
                u = k->padre->padre->derecha;

                if (u->color == ROJO) {
                    k->padre->color = NEGRO;
                    u->color = NEGRO;
                    k->padre->padre->color = ROJO;
                    k = k->padre->padre;
                } else {
                    if (k == k->padre->derecha) {
                        k = k->padre;
                        rotar_izquierda(k);
                    }
                    k->padre->color = NEGRO;
                    k->padre->padre->color = ROJO;
                    rotar_derecha(k->padre->padre);
                }
            } else {
                u = k->padre->padre->izquierda;

                if (u->color == ROJO) {
                    k->padre->color = NEGRO;
                    u->color = NEGRO;
                    k->padre->padre->color = ROJO;
                    k = k->padre->padre;
                } else {
                    if (k == k->padre->izquierda) {
                        k = k->padre;
                        rotar_derecha(k);
                    }
                    k->padre->color = NEGRO;
                    k->padre->padre->color = ROJO;
                    rotar_izquierda(k->padre->padre);
                }
            }
            if (k == raiz) {
                break;
            }
        }
        raiz->color = NEGRO;
    }

    Nodo<T>* buscar_ayudante(Nodo<T>* nodo, T clave) const {
        if (nodo == NODO_NULO || clave == nodo->dato) {
            return nodo;
        }

        if (clave < nodo->dato) {
            return buscar_ayudante(nodo->izquierda, clave);
        }
        return buscar_ayudante(nodo->derecha, clave);
    }

    void en_orden_ayudante(Nodo<T>* nodo, int nivel) const {
        if (nodo != NODO_NULO) {
            en_orden_ayudante(nodo->derecha, nivel + 1);
            std::cout << std::string(4 * nivel, ' ') << nodo->dato << (nodo->color == ROJO ? "(R)" : "(N)") << " " << std::endl;
            en_orden_ayudante(nodo->izquierda, nivel + 1);
        }
    }

    void borrar_arbol_ayudante(Nodo<T>* nodo) {
        if (nodo != NODO_NULO) {
            borrar_arbol_ayudante(nodo->izquierda);
            borrar_arbol_ayudante(nodo->derecha);
            delete nodo;
        }
    }

public:
    ArbolRojoNegro() {
        NODO_NULO = new Nodo<T>(NEGRO);
        raiz = NODO_NULO;
        NODO_NULO->izquierda = NODO_NULO;
        NODO_NULO->derecha = NODO_NULO;
        NODO_NULO->padre = NODO_NULO;
    }

    ~ArbolRojoNegro() {
        borrar_arbol_ayudante(raiz);
        delete NODO_NULO;
    }

    Nodo<T>* buscar(T clave) const {
        return buscar_ayudante(raiz, clave);
    }

    void insertar(T clave) {
        Nodo<T>* nuevo_nodo = new Nodo<T>(clave);
        nuevo_nodo->padre = NODO_NULO;
        nuevo_nodo->izquierda = NODO_NULO;
        nuevo_nodo->derecha = NODO_NULO;

        Nodo<T>* y = NODO_NULO;
        Nodo<T>* x = raiz;

        while (x != NODO_NULO) {
            y = x;
            if (nuevo_nodo->dato < x->dato) {
                x = x->izquierda;
            } else {
                x = x->derecha;
            }
        }

        nuevo_nodo->padre = y;

        if (y == NODO_NULO) {
            raiz = nuevo_nodo;
        } else if (nuevo_nodo->dato < y->dato) {
            y->izquierda = nuevo_nodo;
        } else {
            y->derecha = nuevo_nodo;
        }

        nuevo_nodo->color = ROJO;
        arreglar_insercion(nuevo_nodo);
    }

    void en_orden() const {
        en_orden_ayudante(raiz, 0);
        std::cout << std::endl;
    }

    bool esta_vacio() const {
        return raiz == NODO_NULO;
    }
};

int main() {
    ArbolRojoNegro<int> arbol_rn;

    arbol_rn.insertar(10);
    arbol_rn.en_orden();

    arbol_rn.insertar(5);
    arbol_rn.en_orden();

    arbol_rn.insertar(15);
    arbol_rn.en_orden();

    arbol_rn.insertar(3);
    arbol_rn.en_orden();

    arbol_rn.insertar(2);
    arbol_rn.en_orden();

    arbol_rn.insertar(4);
    arbol_rn.en_orden();

    std::cout << std::endl;
    std::cout << "Buscando 4: " << (arbol_rn.buscar(4) != nullptr ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscando 5: " << (arbol_rn.buscar(5) != nullptr ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscando 6: " << (arbol_rn.buscar(6) != nullptr ? "Encontrado" : "No encontrado") << std::endl;

    arbol_rn.insertar(20);
    arbol_rn.insertar(4);
    arbol_rn.insertar(17);

    arbol_rn.en_orden();

    return 0;
}