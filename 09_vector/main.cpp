#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> lista;
    lista.push_back("dato1");
    lista.push_back("dato2");
    lista.push_back("dato3");

    for (const auto& elemento : lista) {
        std::cout << elemento << std::endl;
    }

    std::cout << lista.size() << std::endl;
    std::cout << lista[2] << std::endl;

    lista.pop_back();

    std::cout << lista.size() << std::endl;
    std::cout << lista[1] << std::endl;

    lista.pop_back();
    std::cout << lista.size() << std::endl;
    std::cout << lista[2] << std::endl;

    return 0;
}
