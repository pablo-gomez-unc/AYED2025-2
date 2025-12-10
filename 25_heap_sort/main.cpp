/**
 * @file main.cpp
 * @brief Programa principal que demuestra el algoritmo de ordenamiento Heap Sort
 * @author Roberto Pablo Gomez
 */

#include <iostream>
using namespace std;

/**
 * @brief Intercambia dos valores enteros
 * @param a Primer valor
 * @param b Segundo valor
 */
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Imprime los elementos de un array
 * @param arr Array a imprimir
 * @param n Tamaño del array
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

/**
 * @brief Mantiene la propiedad de heap en un subárbol
 * @param arr Array que representa el heap
 * @param n Tamaño del heap
 * @param i Índice del nodo raíz del subárbol
 */
void heapify(int arr[], int n, int i) {
    printArray(arr, n);

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        printArray(arr, n);
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = { 60, 3, 11, 2, 70, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: ";
    printArray(arr, n);

    heapsort(arr, n);

    cout << "Arreglo ordenado: ";
    printArray(arr, n);

    return 0;
}
