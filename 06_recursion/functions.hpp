/**
 * @file functions.hpp
 * @brief Declaraciones de funciones para sumatoria y fibonacci (iterativas y recursivas)
 * @author Roberto Pablo Gomez
 */

/**
 * @brief Calcula la sumatoria de 0 a valor de forma iterativa
 * @param valor Valor hasta el cual calcular la sumatoria
 * @return Sumatoria de 0 a valor
 */
int sumatoriaIter(int);

/**
 * @brief Calcula el número de Fibonacci de forma iterativa
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciIter(int);

/**
 * @brief Calcula la sumatoria de 0 a valor de forma recursiva
 * @param valor Valor hasta el cual calcular la sumatoria
 * @return Sumatoria de 0 a valor
 */
int sumatoriaRec(int);

/**
 * @brief Calcula el número de Fibonacci de forma recursiva
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciRec(int);

/**
 * @brief Función auxiliar para calcular Fibonacci con recursión de cola
 * @param y Contador actual
 * @param a1 Primer acumulador
 * @param a2 Segundo acumulador
 * @param x Valor objetivo
 * @return Número de Fibonacci calculado
 */
int fibaux(int, int, int, int);

/**
 * @brief Calcula el número de Fibonacci usando recursión de cola
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciTail(int);

/**
 * @brief Función auxiliar para calcular Fibonacci de forma iterativa optimizada
 * @param y Contador actual
 * @param a1 Primer acumulador
 * @param a2 Segundo acumulador
 * @param x Valor objetivo
 * @return Número de Fibonacci calculado
 */
int fibite(int, int, int, int);

/**
 * @brief Calcula el número de Fibonacci usando iteración optimizada (tail recursion convertida)
 * @param valor Posición en la secuencia de Fibonacci
 * @return Número de Fibonacci en la posición valor
 */
int fibonacciTailIter(int);

