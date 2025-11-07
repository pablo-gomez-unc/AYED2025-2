#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define PRIM_V 4

int minKey(const std::vector<int>& key, const std::vector<bool>& mstSet) {
    int min_val = INT_MAX, min_index = -1;
    for (int v = 0; v < PRIM_V; v++) {
        if (!mstSet[v] && key[v] < min_val) {
            min_val = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(const std::vector<std::vector<int>>& graph) {
    std::vector<int> parent(PRIM_V);
    std::vector<int> key(PRIM_V);
    std::vector<bool> mstSet(PRIM_V, false);

    for (int i = 0; i < PRIM_V; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < PRIM_V - 1; count++) {
        int u = minKey(key, mstSet);
        if (u == -1) break; 

        mstSet[u] = true;

        for (int v = 0; v < PRIM_V; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    std::cout << "--- Algoritmo de Prim (MST) ---" << std::endl;
    std::cout << "Arista \tPeso" << std::endl;
    for (int i = 1; i < PRIM_V; i++) {
        if (parent[i] != -1) { 
             std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << std::endl;
        }
    }
    std::cout << std::endl;
}

struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
            return true;
        }
        return false;
    }
};

struct Vertice {
    int u, v, weight;
    bool operator<(const Vertice& w) const {
        return weight < w.weight;
    }
};

void kruskalMST(int V, std::vector<Vertice>& vertices) {
    std::sort(vertices.begin(), vertices.end());
    DSU dsu(V);
    std::vector<Vertice> mstVertices;
    long long totalWeight = 0;

    std::cout << "--- Algoritmo de Kruskal (MST) ---" << std::endl;
    for (const Vertice vertice : vertices) {
        if (dsu.unite(vertice.u, vertice.v)) {
            mstVertices.push_back(vertice);
            totalWeight += vertice.weight;
            if (mstVertices.size() == V - 1) {
                break;
            }
        }
    }

    std::cout << "Arista \tPeso" << std::endl;
    for (const Vertice& edge : mstVertices) {
        std::cout << edge.u << " - " << edge.v << "\t" << edge.weight << std::endl;
    }
    std::cout << "Peso total del MST: " << totalWeight << std::endl;
    std::cout << std::endl;
}


int main() {
    std::vector<std::vector<int>> grafo_matrix = {
        {0 , 10, 30, 25},
        {10, 0 , 15, 20},
        {30, 15, 0 , 5},
        {25, 20, 5 , 0},
    };
    primMST(grafo_matrix);

    int kruskal_V = 4;
    std::vector<Vertice> grafo_lista = {
        {0, 1, 10},
        {0, 2, 30},
        {0, 3, 25},
        {1, 2, 15},
        {1, 3, 20},
        {2, 3, 5},
    };
    kruskalMST(kruskal_V, grafo_lista);
    return 0;
}