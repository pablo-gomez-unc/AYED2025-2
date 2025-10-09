#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Metodo para imprimir vector con el formato:
 * 1 2 3 4 
 * 
 * @param arr el vector a imprimir
 */
void imprimirVector(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int particion(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            std::swap(arr[i], arr[j]); 
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1); 
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = particion(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> datos = {10, 7, 8, 9, 1, 5};
    int n = datos.size();

    std::cout << "Vector original: ";
    imprimirVector(datos);

    quickSort(datos, 0, n - 1);

    std::cout << "Vector ordenado: ";
    imprimirVector(datos);

    return 0;
}