#include <stdio.h>
int fib(int i) {
    if (i < 2) 
        return i;
    else
        return fib(i-1) + fib(i-2);
}

int main() {
    printf("%d\n", fib(40));
}
