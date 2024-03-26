#include <iostream>

// Función de plantilla variádica que utiliza una expresión plegable
template<typename... Args>
auto sum(Args... args) {
    return (... + args); // Expresión plegable
}

int main() {
    std::cout << "La suma de 1, 2, 3 es: " << sum(1, 2, 3) << std::endl;
    std::cout << "La suma de 4, 5, 6, 7 es: " << sum(4, 5, 6, 7) << std::endl;

    return 0;
}