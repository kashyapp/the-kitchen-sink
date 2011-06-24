#include <iostream>
int fib(int i) {
    if (i < 2) 
        return i;
    else
        return fib(i-1) + fib(i-2);
}

int main() {
    std::cout << fib(40) << std::endl;
}
