#include <stdio.h>

int factcount(int n) {
    int five = 5;
    int i;
    int count = 0;
    for (i = 1; i <= n; i++) {
        int t = i;
        while (t % 5 == 0) {
            count++;
            t = t / 5;
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);

    int n, i;
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", factcount(n));
    }
    return 0;
}
