#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

    void agregarVertice(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            matrizAdj[u][v] = 1;
            matrizAdj[v][u] = 1; 
        } else {
            std::cout << "Error: Vertice fuera de rango." << std::endl;
        }
    }

    void bfs(int nodoInicio) {
        if (nodoInicio < 0 || nodoInicio >= numVertices) {
            return;
        }

        std::vector<bool> visitados(numVertices, false); 
        std::queue<int> q;
        visitados[nodoInicio] = true;
        q.push(nodoInicio);

        std::cout << "Recorrido BFS comenzando desde el nodo " << nodoInicio << ": ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            std::cout << u << " ";
            for (int v = 0; v < numVertices; ++v) {
                if (matrizAdj[u][v] == 1 && !visitados[v]) {
                    visitados[v] = true;
                    q.push(v);
                }
            }
        }
        std::cout << std::endl;
    }

    void dfs(int nodoInicio) {
        if (nodoInicio < 0 || nodoInicio >= numVertices) {
            return;
        }

        std::vector<bool> visitados(numVertices, false);
        std::stack<int> s;
        s.push(nodoInicio);

        std::cout << "Recorrido DFS comenzando desde el nodo " << nodoInicio << ": ";
        while (!s.empty()) {
            int u = s.top(); s.pop();
            if (!visitados[u]) {
                visitados[u] = true;
                std::cout << u << " ";
                for (int v = numVertices - 1; v >= 0; --v) {
                    if (matrizAdj[u][v] == 1 && !visitados[v]) {
                        s.push(v);
                    }
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Grafo g(6); 

    g.agregarVertice(0, 1);
    g.agregarVertice(0, 2);
    g.agregarVertice(1, 2);
    g.agregarVertice(1, 3);
    g.agregarVertice(1, 4);
    g.agregarVertice(2, 4);

    g.bfs(1);
    g.dfs(1);

    Grafo g2(7);
    g2.agregarVertice(0,6);
    g2.agregarVertice(0,1);
    g2.agregarVertice(1,3);
    g2.agregarVertice(1,4);
    g2.agregarVertice(2,5);
    g2.agregarVertice(2,6);
    g2.agregarVertice(2,4);
    g2.bfs(1);
    g2.dfs(1);

    return 0;
}