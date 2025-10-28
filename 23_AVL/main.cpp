#include <iostream>
#include <string>

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    int altura;
    Nodo(int v) : valor(v), izq(nullptr), der(nullptr), altura(1) {}
};

int max(int a , int b) {
    return a > b ? a : b;
}

class AVL {
private:
    Nodo* raiz = nullptr;

    int altura(Nodo* n) {
        if (n == nullptr) {
            return 0;
        }
        return n->altura;
    }

    int balance(Nodo* n) {
        if (n == nullptr) {
            return 0;
        }
        return altura(n->izq) - altura(n->der);
    }

    void actualizarAltura(Nodo* n) {
        if (n==nullptr) {
            return;
        }
        n->altura = 1 + max(altura(n->izq), altura(n->der));
    }

    Nodo* rotarDerecha(Nodo* y) {
        Nodo* x = y->izq;
        Nodo* T2 = x->der;

        x->der = y;
        y->izq = T2;

        actualizarAltura(y);
        actualizarAltura(x);

        return x;
    }

    Nodo* rotarIzquierda(Nodo* x) {
        Nodo* y = x->der;
        Nodo* z = y->izq;

        y->izq = x;
        x->der = z;

        actualizarAltura(x);
        actualizarAltura(y);

        return y;
    }

    Nodo* insertar(Nodo* nodo, int valor) {
        if (!nodo) return new Nodo(valor);

        if (valor < nodo->valor)
            nodo->izq = insertar(nodo->izq, valor);
        else if (valor > nodo->valor)
            nodo->der = insertar(nodo->der, valor);
        else
            return nodo;

        actualizarAltura(nodo);

        int b = balance(nodo);

        if (b > 1 && valor < nodo->izq->valor)
            return rotarDerecha(nodo);

        if (b < -1 && valor > nodo->der->valor)
            return rotarIzquierda(nodo);

        if (b > 1 && valor > nodo->izq->valor) {
            nodo->izq = rotarIzquierda(nodo->izq);
            return rotarDerecha(nodo);
        }

        if (b < -1 && valor < nodo->der->valor) {
            nodo->der = rotarDerecha(nodo->der);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }

    void imprimir(Nodo* nodo, int nivel = 0) {
        if (!nodo) return;
        imprimir(nodo->der, nivel + 1);
        std::cout << std::string(4 * nivel, ' ') << nodo->valor << std::endl;
        imprimir(nodo->izq, nivel + 1);
    }

    void liberar(Nodo* nodo) {
        if (!nodo) return;
        liberar(nodo->izq);
        liberar(nodo->der);
        delete nodo;
    }

public:
    ~AVL() { liberar(raiz); }
    void insertar(int valor) { raiz = insertar(raiz, valor);}
    void imprimir() { imprimir(raiz); }
};

int main() {
    AVL arbol;

    int valores[] = {30, 20, 25};
    for (int val : valores) {
        std::cout << "Insertando: " << val << std::endl;
        arbol.insertar(val);
        arbol.imprimir();
    }

    return 0;
}

