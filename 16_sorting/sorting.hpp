//
// Created by Roberto Pablo Gomez on 31/03/2025.
//

#ifndef BUBBLE_AA_HPP
#define BUBBLE_AA_HPP

#include <iostream>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int suma (int n) {
    if (n == 0) {
        return 0;
    }
    return n + suma(n-1);
}

void burbuja(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void burbuja_aux(int array[], int n, int i, int j) {
    if (j == n-i-1 ) return;
    if (array[j] > array[j+1]) {
        swap(array[j], array[j+1]);
    }
    burbuja_aux(array, n, i, j+1);
}

void burbuja_recursivo(int array[], int n, int i) { // 3 , 1 , 2 br(a, 3, 0)
    if ( i == n-1) return;
    burbuja_aux(array, n, i, 0);
    burbuja_recursivo(array, n, i+1);
}

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

void imprimir(int* array, int n) {
    for (int i = 0; i < n; i++){
        std::cout << array[i] << " -> " ;
    }
    std::cout << "FINAL" << std::endl;
}

bool iguales(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

#endif //BUBBLE_AA_HPP
