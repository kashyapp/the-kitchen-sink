#include <cstdlib>
#include <iostream>
int fib(int i) {
    if (i < 2) 
        return i;
    else
        return fib(i-1) + fib(i-2);
}

int main(int argc, char **argv) {
	if (argc < 2) return 1;
    std::cout << fib(std::atoi(argv[1])) << std::endl;

	return 0;
}
