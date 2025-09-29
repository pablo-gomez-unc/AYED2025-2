#include <iostream>
#include "sorting.hpp"

int main() {
    std::cout << "2025 - Ordenamiento parte 1" << std::endl;

    int array[] = {10, 32, 5, 13, 42, 5, 99};
    int n = 7;
    imprimir(array,n);
    burbuja(array, n);
    imprimir(array,n);
    int array_rec[] = {10, 32, 5, 13, 42, 5, 99};
    n = 7;
    imprimir(array_rec,n);
    burbuja_recursivo(array_rec, n, 0);
    imprimir(array_rec,n);

    std::cout << "-----" << std::endl;

    int array2[] = {10, 32, 5, 13, 42, 5, 99};
    n = 7;
    imprimir(array2,n);
    seleccion(array2, n);
    imprimir(array2,n);
    int array2_rec[] = {10, 32, 5, 13, 42, 5, 99};
    n = 7;
    imprimir(array2_rec,n);
    seleccion_recursivo(array2_rec, n, 0);
    imprimir(array2_rec,n);

    std::cout << "-----" << std::endl;

    int array3[] = {10, 32, 5, 13, 42, 5, 99};
    n = 7;
    imprimir(array3,n);
    insercion(array3, n);
    imprimir(array3,n);
    int array3_rec[] = {10, 32, 5, 13, 42, 5, 99};
    n = 7;
    imprimir(array3_rec,n);
    insercion_recursivo(array3_rec, n, 1);
    imprimir(array3_rec,n);

    return 0;
}

