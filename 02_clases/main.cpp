#include <iostream>

class Persona {
public:
    Persona(): edad(0), nombre(std::string("hola")) {};
    int edad;
    std::string nombre;
};

class PersonaConst {
public:
    PersonaConst(): edad(0), nombre(std::string("")) {};
    PersonaConst(int e, std::string n): edad(e), nombre(n) {};
    void mostrar() {
      std::cout << edad << "  " << nombre << std::endl;
    };
private:
    int edad;
    std::string nombre;
};

int main() {
    Persona p;
    std::cout << p.edad << std::endl;
    std::cout << p.nombre << std::endl;
    Persona p1 = Persona();

    Persona *p2 = new Persona();
    std::cout << p2->edad << std::endl;
    std::cout << p2->nombre << std::endl;
    std::cout << (*p2).edad << std::endl;
    std::cout << (*p2).nombre << std::endl;
    delete p2;

    PersonaConst pc = PersonaConst(22, "pepe");
    pc.mostrar();

    PersonaConst *pc1 = new PersonaConst(22, "pepe");
    pc1->mostrar();
    delete pc1;

    PersonaConst pi;
    PersonaConst pi1(22, std::string ("aa"));
    PersonaConst pi2{22, "jj"};

    return 0;
}