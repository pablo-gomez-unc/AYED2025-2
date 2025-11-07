#include <iostream>
#include <vector>
#include <queue>    
#include <limits>   

const int INF = std::numeric_limits<int>::max(); 

void dijkstra(int V, const std::vector<std::vector<std::pair<int, int>>>& adj, int origen, int destino) {
    std::vector<int> distancias(V, INF);
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > pq;
    std::vector<int> parents(V, -1);

    distancias[origen] = 0;   
    pq.push({0, origen});

    while (!pq.empty()) {
        int distancia = pq.top().first;  
        int u = pq.top().second; 
        pq.pop();

        if (distancia > distancias[u]) {
            continue;
        }
        for (const auto& vertice : adj[u]) {
            int v = vertice.first;     
            int peso = vertice.second; 

            if (distancias[u] + peso < distancias[v]) {
                parents[v] = u;
                distancias[v] = distancias[u] + peso; 
                pq.push({distancias[v], v});     
            }
        }
    }

    std::cout << "\nDistancias mas cortas desde el origen " << origen << ":" << std::endl;
    for (int i = 0; i < V; ++i) {
        if (distancias[i] == INF) {
            std::cout << "Vertice " << i << ": INF (inalcanzable)" << std::endl;
        } else {
            std::cout << "Vertice " << i << ": " << distancias[i] << std::endl;
        }
    }

    while (destino != -1) {
        std::cout << destino << " ";
        destino = parents[destino];
    }
    std::cout << std::endl;
}

int main() {
    int V = 5;

    std::vector<std::vector<std::pair<int, int>>> adj(V);
    adj[0].push_back({1, 4}); 
    adj[0].push_back({2, 2});  
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 2}); 
    adj[1].push_back({4, 3}); 
    adj[2].push_back({1, 1});
    adj[2].push_back({4, 5});
    adj[2].push_back({3, 4});
    adj[4].push_back({3, 1});

    dijkstra(V, adj, 0, 3);

    std::vector<std::vector<std::pair<int, int>>> adj1(V);
    adj1[0].push_back({1, 4}); 
    adj1[0].push_back({2, 2});  
    adj1[1].push_back({2, 3});
    adj1[1].push_back({3, 5}); 
    adj1[1].push_back({4, 3}); 
    adj1[2].push_back({1, 1});
    adj1[2].push_back({4, 2});
    adj1[2].push_back({3, 4});
    adj1[4].push_back({3, 1});

    dijkstra(V, adj1, 0, 3);
    return 0;
}