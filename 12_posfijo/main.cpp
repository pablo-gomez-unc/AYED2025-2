#include <iostream>
#include <sstream>
#include "pila.hpp"

void procesar (Pila<std::string>* p) {
    if (p->tope() == "*" || p->tope() == "+" || p->tope() == "-" || p->tope() == "/"){
        std::string operador = p->desapilar();
        int operando2 = std::stoi(p->desapilar());
        int operando1 = std::stoi(p->desapilar());

        int resultado;
        if (operador == "*") {
            resultado = operando1 * operando2;
        } else if (operador == "+") {
            resultado = operando1 + operando2;
        } else if (operador == "-") {
            resultado = operando1 - operando2;
        } else if (operador == "/") {
            resultado = operando1 / operando2;
        } else {
            throw std::runtime_error("Operador inválido");
        }
        p->apilar(std::to_string(resultado));
    }
}

int main() {
    std::cout << "Posfijo 2025" << std::endl;
    auto *p = new Pila<std::string>();

    std::string expresion = "4 5 6 * + 2 /";
    std::stringstream s_stream(expresion);
    std::string item;

    while (std::getline(s_stream, item, ' ')) {
        p->apilar(item);
        p->imprimir();
        procesar(p);
    }

    p->imprimir();

    delete p;
    return 0;
}
