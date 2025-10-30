#include <iostream>
#include <vector>
#include <list> 

class GrafoLista {
private:
    std::vector<std::list<int>> listaAdj;
    int numVertices;

public:
    GrafoLista(int vertices) {
        numVertices = vertices;
        listaAdj.resize(numVertices); 
    }

    void agregarArista(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            listaAdj[u].push_back(v);
            listaAdj[v].push_back(u); 
        } else {
            std::cout << "Error: Vertice fuera de rango." << std::endl;
        }
    }

    void imprimir() {
        std::cout << "Lista de Adyacencia:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertice " << i << ":";
            if (listaAdj[i].empty()) {
                std::cout << " (ninguno)";
            } else {
                for (int vecino : listaAdj[i]) {
                    std::cout << " -> " << vecino;
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::cout << "Ejemplo de Grafo con Lista de Adyacencia" << std::endl;
    GrafoLista g_lista(3);

    g_lista.agregarArista(0, 1);
    g_lista.agregarArista(0, 2);
    g_lista.agregarArista(1, 2);
    g_lista.imprimir();

    return 0;
}