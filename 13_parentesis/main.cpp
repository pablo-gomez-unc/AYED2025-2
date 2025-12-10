/**
 * @file main.cpp
 * @brief Programa principal que verifica el balanceo de paréntesis, corchetes y llaves
 * @author Roberto Pablo Gomez
 */

#include <iostream>
#include "pila.hpp"
#include "lista.hpp"

/**
 * @brief Procesa un carácter para verificar el balanceo de la expresión
 * @param p Puntero a la pila de caracteres
 * @param actual Carácter actual a procesar
 */
void procesar(Pila<char>* p, char actual){
    if (actual == '}' ||  actual == ']' || actual == ')'  ) {
        char anterior = p->desapilar();
        if (
            (actual == '}' && anterior != '{') ||
            (actual == ']' && anterior != '[') ||
            (actual == ')' && anterior != '(')
        ) {
            throw std::runtime_error("Expresión no balanceada");
        }
        return;
    }
    p->apilar(actual);
}

/**
 * @brief Función principal del programa
 * @return 0 si el programa termina correctamente
 */
int main() {
    std::cout << "Parentesis 2025" << std::endl;
    auto *l = new Lista<char>();

    std::string expresion = "{[()()]}";
    for (char c: expresion){
        l->agregar_final(c);
    }
    l->imprimir();

    auto *p = new Pila<char>();
    int tamanio_inicial = l->tamanio();
    for (int i = 0; i < tamanio_inicial; i++){
        char actual = l->final();
        l->eliminar_inicio();
        procesar(p, actual);
        p->imprimir();
    }
    std::cout << "Expresion Balanceada";
    delete p;
    return 0;
}
