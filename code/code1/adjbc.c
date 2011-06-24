#include <stdio.h>
#include <assert.h>

#define MAXLEN 201

void mult(char *s, int *l, int m) {
    int i ,temp, carry;
    for (i = 0, carry = 0; i < *l; i++) {
        temp = s[i] * m + carry;
        s[i] = temp % 10;
        carry = temp / 10;
    }
    while (carry > 0) {
        s[(*l)++] = carry % 10;
        carry = carry / 10;
    }
}

void print(char *s, int l) {
    int i = 0;
    int count = 0;
    while (i < l && s[i++] == 0) {
        count++;
    }
    fprintf(stderr, "%d\n", count);
}

void factorial(char *s, int n) {
    s[0] = 1;
    int l = 1;
    int i;
    for (i = 2; i <= n; i++) {
        mult(s, &l, i);
        print(s, l);
        assert(l < MAXLEN);
    }
    for (i = 0; i < l; i++) {
        s[i] += '0';
    }
    for (i = 0; i < l/2; i++) {
        char t = s[i];
        s[i] = s[l-i-1];
        s[l-i-1] = t;
    }
    s[l] = '\0';
}

int main() {
    int t;
    scanf("%d", &t);
    char s[MAXLEN];

    int n, i;
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        factorial(&s[0], n);
        printf("%s\n", s);
    }
    return 0;
}
