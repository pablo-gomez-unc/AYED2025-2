#include <iostream>
#include "pila.hpp"
#include "lista.hpp"

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
