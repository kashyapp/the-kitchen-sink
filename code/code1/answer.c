#include <stdio.h>

int main() {

    int i;
    while (scanf("%d",&i)) {
        if (i == 42) {
            break;
        } else {
            printf("%d\n", i);
            printf("%d\n", i);
        }
    }
    return 0;
}
