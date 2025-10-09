#include <iostream>

void imprimir (int* arr, int n) {
    std::cout << " | ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " | ";
    }
    std::cout << std::endl;
}

void merge(int* arr, int inicio, int medio, int final) {
    int* ordenado = new int[final - inicio + 1];

    int i = inicio, j = medio+1, k = 0;
    while ( i < medio+1 && j < final+1 ) {
        if (arr[i] < arr[j]) {
            ordenado[k++] = arr[i++];
        } else {
            ordenado[k++] = arr[j++];
        }
    }
    while (i < medio+1) {
        ordenado[k++] = arr[i++];
    };
    while (j < final+1) {
        ordenado[k++] = arr[j++];
    };
    for (int i = 0; i < final+1; i++) {
        arr[inicio+i] = ordenado[i];
    }

    delete [] ordenado;
}

void merge_sort (int* arr, int i, int f) {
    if (i >= f) return;

    int medio = i + (f - i) / 2;
    imprimir(arr+i, medio-i+1);
    merge_sort (arr, i, medio);
    imprimir(arr+medio+1, f-medio);
    merge_sort (arr, medio+1, f);
    merge (arr, i, medio, f);
    imprimir(arr, f-i+1);
}

int main() {
    std::cout << "Merge 2025" << std::endl;
    int arr[] = {66, 11, 2, 3, 44};
    int n = std::size(arr);

    imprimir(arr, n);
    merge_sort (arr, 0, n - 1);
    imprimir(arr, n);

    return 0;
}