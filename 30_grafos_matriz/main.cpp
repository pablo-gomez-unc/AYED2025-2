#include <iostream>
#include <vector>
#include <iomanip> 

class Grafo {
private:
    std::vector<std::vector<int>> matrizAdj;
    int numVertices;

public:
    Grafo(int vertices) {
        numVertices = vertices;
        matrizAdj.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void agregarArista(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            matrizAdj[u][v] = 1;
            matrizAdj[v][u] = 1; 
        } else {
            std::cout << "Error: Vertice fuera de rango." << std::endl;
        }
    }

    void printGraph() {
        std::cout << "Matriz de Adyacencia:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << std::setw(2) << matrizAdj[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::cout << "Ejemplo de Grafo con Matriz de Adyacencia" << std::endl;
    Grafo g_matriz(3); 

    g_matriz.agregarArista(0, 1);
    g_matriz.agregarArista(0, 2);
    g_matriz.agregarArista(1, 2);
    g_matriz.printGraph();

    return 0;
}