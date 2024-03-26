#include <iostream>

template <int N>
struct Unroll {
    static void loop() {
        Unroll<N-1>::loop();
        std::cout << "Iteration: " << N << std::endl;
    }
};

template <>
struct Unroll<0> {
    static void loop() {
        std::cout << "Iteration: 0" << std::endl;
    }
};

int main() {
    Unroll<10>::loop(); // Cambia el valor de 10 por el número de iteraciones que desees
    return 0;
}