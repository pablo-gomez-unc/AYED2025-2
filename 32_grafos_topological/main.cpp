#include <iostream>
#include <vector>
#include <list>   
#include <queue>
#include <string>
#include <vector>

class GrafoDirigido {
public:
    int numNodes;
    std::vector<std::list<int>> adj;
    std::vector<std::string> nodeNames;

    GrafoDirigido(int n, const std::vector<std::string>& names) : numNodes(n) {
        if (names.size() != static_cast<size_t>(n)) {
            std::cerr << "Error: El número de nodos y la cantidad de nombres no coinciden." << std::endl;
        }
        this->nodeNames = names; 
        adj.resize(numNodes);
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < numNodes && v >= 0 && v < numNodes) {
            adj[u].push_back(v);
        } else {
            std::cerr << "Error: Vertice fuera de rango al aniadir arista (" << u << " -> " << v << ")" << std::endl;
        }
    }

    std::vector<int> kahnTopologicalSort() {
        std::vector<int> in_degree(numNodes, 0); 
        std::vector<int> sorted_order_ids;
        std::queue<int> q;

        for (int u = 0; u < numNodes; ++u) {
            for (int v : adj[u]) {
                in_degree[v]++;
            }
        }

        for (int i = 0; i < numNodes; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        int count_visited_nodes = 0;

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            sorted_order_ids.push_back(u);
            count_visited_nodes++;

            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v); 
                }
            }
        }

        if (count_visited_nodes != numNodes) {
            std::cerr << "Error: El grafo contiene un ciclo. No se puede generar una ordenación topológica completa." << std::endl;
            return {}; 
        }

        return sorted_order_ids;
    }
};

int main() {
    std::vector<std::string> prendas = {
        "Ropa Interior", // ID: 0
        "Medias",        // ID: 1
        "Pantalones",    // ID: 2
        "Camisa",        // ID: 3
        "Zapatos",       // ID: 4
        "Cinturon",      // ID: 5
        "Corbata",       // ID: 6
        "Reloj",         // ID: 7
        "Abrigo"         // ID: 8
    };
    int numPrendas = prendas.size();

    GrafoDirigido g(numPrendas, prendas);
    g.addEdge(0, 2); // Ropa Interior -> Pantalones
    g.addEdge(0, 3); // Ropa Interior -> Camisa
    g.addEdge(1, 4); // Medias -> Zapatos
    g.addEdge(2, 4); // Pantalones -> Zapatos
    g.addEdge(2, 5); // Pantalones -> Cinturón
    g.addEdge(2, 8); // Pantalones -> Abrigo
    g.addEdge(3, 5); // Camisa -> Cinturón
    g.addEdge(3, 6); // Camisa -> Corbata
    g.addEdge(3, 7); // Camisa -> Reloj
    g.addEdge(3, 8); // Camisa -> Abrigo
    g.addEdge(6, 8); // Corbata -> Abrigo
    g.addEdge(7, 8); // Reloj -> Abrigo

    std::vector<int> sorted_ids = g.kahnTopologicalSort();
    if (!sorted_ids.empty()) {
        std::cout << "Un orden logico para vestirse es:" << std::endl;
        for (size_t i = 0; i < sorted_ids.size(); ++i) {
            std::cout << g.nodeNames[sorted_ids[i]];
            if (i < sorted_ids.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}