#include <iostream>

template <int N, typename Func>
struct Unroll {
    static void execute(Func func) {
        Unroll<N-1, Func>::execute(func);
        func(N);
    }
};

template <typename Func>
struct Unroll<0, Func> {
    static void execute(Func func) {
        func(0);
    }
};

void myFunction(int n) {
    std::cout << "Iteration " << n << std::endl;
}

int main() {
    Unroll<5, decltype(myFunction)>::execute(myFunction);
    return 0;
}