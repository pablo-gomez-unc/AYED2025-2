/**
 * @file functions.cpp
 * @brief Implementación de funciones para sumatoria y fibonacci
 * @author Roberto Pablo Gomez
 */

#include "functions.hpp"
#include <stdexcept> // For std::runtime_error

/**
 * @brief Calcula la sumatoria de 0 a valor de forma iterativa
 * @param valor Valor hasta el cual calcular la sumatoria
 * @return Sumatoria de 0 a valor
 */
int sumatoriaIter(int valor) {
    int resultado = 0;
    for (int i = 0; i <= valor; i++){
        resultado += i;
    }
    return resultado;
}

/**
 * @brief Calcula la sumatoria de 0 a valor de forma recursiva
 * @param valor Valor hasta el cual calcular la sumatoria
 * @return Sumatoria de 0 a valor
 * @throws std::runtime_error Si valor es negativo
 */
int sumatoriaRec(int valor) {
    if (valor < 0) {
        throw new std::runtime_error("no se puede calcular sumatoria");
    }
    if (valor == 0) {
        return 0;
    }
    return valor + sumatoriaRec(valor - 1);
}

/**
 * @brief Calcula el número de Fibonacci de forma iterativa
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciIter(int valor) {
    if (valor == 0) return 0;
    if (valor == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= valor; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/**
 * @brief Calcula el número de Fibonacci de forma recursiva
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciRec(int valor) {
    if (valor == 1 || valor == 2){
        return 1;
    } 
    return fibonacciRec(valor-1) + fibonacciRec(valor - 2);
}

/**
 * @brief Función auxiliar para calcular Fibonacci con recursión de cola
 * @param y Contador actual
 * @param a1 Primer acumulador
 * @param a2 Segundo acumulador
 * @param x Valor objetivo
 * @return Número de Fibonacci calculado
 */
int fibaux(int y, int a1, int a2, int x){
    if(y == x){
        return a1 + a2;
    }
    return fibaux(y+1, a1 + a2, a1, x);
}

/**
 * @brief Calcula el número de Fibonacci usando recursión de cola
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciTail(int valor){
    if (valor == 1 || valor == 2){
        return 1;
    }
    return fibaux (3, 1, 1, valor);
}

/**
 * @brief Función auxiliar para calcular Fibonacci de forma iterativa optimizada
 * @param y Contador actual
 * @param a1 Primer acumulador
 * @param a2 Segundo acumulador
 * @param x Valor objetivo
 * @return Número de Fibonacci calculado
 */
int fibite(int y, int a1, int a2, int x){
    while (y != x){
        int aux = a1;
        y++;
        a1 = a1 + a2;
        a2 = aux;
    }
    return a1 + a2;
}

/**
 * @brief Calcula el número de Fibonacci usando iteración optimizada (tail recursion convertida)
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciTailIter(int valor){
    if (valor == 1 || valor == 2){
        return 1;
    }
    return fibite (3, 1, 1, valor);
}
