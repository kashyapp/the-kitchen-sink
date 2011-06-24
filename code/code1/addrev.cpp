#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

inline int get(char *s, int n, int i) {
     return (i < n) ? s[i] - '0' : 0;
}
void addrev(char *p, char *q) {
    int p_size = strlen(p);
    int q_size = strlen(q);
    int n = max(p_size, q_size);
    int carry = 0;
    bool leading = true;
    for (int i=0; i < n; i++) {
        int sum = get(p, p_size, i) + get(q, q_size, i) 
            + carry;
        if (leading && sum == 10) {
            carry = 1;
        } else if (sum >= 10) {
            carry = 1;
            putchar(sum - 10 + '0');
            leading = false;
        } else {
            carry = 0;
            putchar(sum + '0');
            leading = false;
        }
    }
    
    if (carry) {
        putchar(carry + '0');
    }

    putchar('\n');
}

int main() {
    int n;
    scanf("%d", &n);
    char p[16];
    char q[16];
    while (n--) {
        scanf("%s", p);
        scanf("%s", q);
        addrev(p,q);
    }
}
