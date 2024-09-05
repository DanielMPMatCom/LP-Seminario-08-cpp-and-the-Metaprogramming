#include <bits/stdc++.h>

using namespace std;

constexpr int Fib(const int& n)
{
    if(n == 0)
        return 0;
    
    if(n == 1)
        return 1;
    
    return Fib(n-1) + Fib(n-2);
}

constexpr int value = 7;
constexpr int fibo = Fib(value);

int main()
{
    cout << fibo;
}