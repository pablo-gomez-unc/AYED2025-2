/**
 * @file main.cpp
 * @brief Programa principal que demuestra el algoritmo de ordenamiento Merge Sort
 * @author Roberto Pablo Gomez
 */

#include <iostream>

/**
 * @brief Imprime los elementos de un array
 * @param arr Array a imprimir
 * @param n Tamaño del array
 */
void imprimir (int* arr, int n) {
    std::cout << " | ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " | ";
    }
    std::cout << std::endl;
}

/**
 * @brief Fusiona dos subarrays ordenados
 * @param arr Array completo
 * @param inicio Índice de inicio
 * @param medio Índice medio
 * @param final Índice final
 */
void merge(int* arr, int inicio, int medio, int final) {
    int* ordenado = new int[final - inicio + 1];

    int i = inicio;
    int j = medio+1; 
    int k = 0;
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

/**
 * @brief Ordena un array usando el algoritmo Merge Sort
 * @param arr Array a ordenar
 * @param i Índice inicial
 * @param f Índice final
 */
void merge_sort (int* arr, int i, int f) {
    if (i >= f) return;

    int medio = i + (f - i) / 2;
    //imprimir(arr+i, medio-i+1);
    merge_sort (arr, i, medio);
    //imprimir(arr+medio+1, f-medio);
    merge_sort (arr, medio+1, f);
    merge (arr, i, medio, f);
    //imprimir(arr, f-i+1);
}

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    std::cout << "Merge 2025" << std::endl;
    int arr[] = {66, 11, 2, 3, 44};
    int n = std::size(arr);

    imprimir(arr, n);
    merge_sort (arr, 0, n - 1);
    imprimir(arr, n);

    return 0;
}

// 1, 2, 3 , 4, 5, 6 ,7 ,8                    n = 8 
// 1,2,3,4.     5,6,7,8.                      n/2
// 1,2.        3,4.      5,6.    7,8.         n/4
// 1    2.     3.    4     5.  6.    7.  8    n/8

// 1,2,3,4.          n=4
// 1,2.   3,4.       n/2 
// 1.   2.   3.   4. n/4 

// log2 (1000000) = 20
// log2 (8) = 3
// log2 (4) = 2
// log2 (2) = 1
// log2 (1)
// n log (n)   