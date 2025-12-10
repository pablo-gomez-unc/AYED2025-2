/**
 * @file sorting.hpp
 * @brief Algoritmos de ordenamiento: burbuja, selección e inserción (iterativos y recursivos)
 * @author Roberto Pablo Gomez
 * @date 31/03/2025
 */

#ifndef BUBBLE_AA_HPP
#define BUBBLE_AA_HPP

#include <iostream>

/**
 * @brief Intercambia dos valores enteros
 * @param a Primer valor
 * @param b Segundo valor
 */
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Calcula la sumatoria de 0 a n de forma recursiva
 * @param n Valor hasta el cual calcular la sumatoria
 * @return Sumatoria de 0 a n
 */
int suma (int n) {
    if (n == 0) {
        return 0;
    }
    return n + suma(n-1);
}

/**
 * @brief Ordena un array usando el algoritmo de burbuja (iterativo)
 * @param array Array a ordenar
 * @param n Tamaño del array
 */
void burbuja(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

/**
 * @brief Función auxiliar recursiva para burbuja
 * @param array Array a ordenar
 * @param n Tamaño del array
 * @param i Índice externo
 * @param j Índice interno
 */
void burbuja_aux(int array[], int n, int i, int j) {
    if (j == n-i-1 ) return;
    if (array[j] > array[j+1]) {
        swap(array[j], array[j+1]);
    }
    burbuja_aux(array, n, i, j+1);
}

/**
 * @brief Ordena un array usando el algoritmo de burbuja (recursivo)
 * @param array Array a ordenar
 * @param n Tamaño del array
 * @param i Índice actual
 */
void burbuja_recursivo(int array[], int n, int i) {
    if ( i == n-1) return;
    burbuja_aux(array, n, i, 0);
    burbuja_recursivo(array, n, i+1);
}

/**
 * @brief Ordena un array usando el algoritmo de selección (iterativo)
 * @param array Array a ordenar
 * @param n Tamaño del array
 */
void seleccion(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
    }
}

/**
 * @brief Función auxiliar recursiva para selección
 * @param array Array a ordenar
 * @param n Tamaño del array
 * @param j Índice actual
 * @param min_index Índice del mínimo encontrado
 */
void seleccion_aux (int array[], int n, int j, int& min_index) {
    if (j == n) return;
    if (array[j] < array[min_index]) {
        min_index = j;
    }
    seleccion_aux(array, n, j+1, min_index);
}

void seleccion_recursivo(int array[], int n, int i) {
    if (i == n-1) return;
    int min_index = i;
    seleccion_aux(array, n, i+1, min_index);
    swap(array[i], array[min_index]);
    seleccion_recursivo(array, n, i+1);
}

/**
 * @brief Ordena un array usando el algoritmo de inserción (iterativo)
 * @param array Array a ordenar
 * @param n Tamaño del array
 */
void insercion(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

/**
 * @brief Función auxiliar recursiva para inserción
 * @param array Array a ordenar
 * @param n Tamaño del array
 * @param j Índice actual
 * @param key Valor a insertar
 */
void insercion_aux (int array[], int n, int& j, int key) {
    if (j < 0 || array[j] <= key) return;
    array[j+1] = array[j];
    j = j - 1;
    insercion_aux(array, n, j, key);
}

void insercion_recursivo (int array[], int n, int i) {
    if (i == n) return;
    int j = i - 1;
    int key = array[i];
    insercion_aux(array, n, j, key);
    array[j+1] = key;
    insercion_recursivo(array, n, i+1);
}

/**
 * @brief Imprime los elementos de un array
 * @param array Array a imprimir
 * @param n Tamaño del array
 */
void imprimir(int* array, int n) {
    for (int i = 0; i < n; i++){
        std::cout << array[i] << " -> " ;
    }
    std::cout << "FINAL" << std::endl;
}

/**
 * @brief Compara dos arrays para verificar si son iguales
 * @param arr1 Primer array
 * @param arr2 Segundo array
 * @param n Tamaño de los arrays
 * @return true si los arrays son iguales, false en caso contrario
 */
bool iguales(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

#endif //BUBBLE_AA_HPP
