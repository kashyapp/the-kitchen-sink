#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 100010
long long a[MAX];
long long b[MAX];

void play(long long *a, long long *b, int &i, int &j) {
    if((a[i] <= b[j] && i > 0) 
            || (i > 0 && j > 0 && (a[i] + a[i-1]) > (b[j] + b[j-1]))) {
        a[i-1] = a[i] + a[i-1];
        i--;
    } else if(a[i] > b[j]) {
        j--;
    }
}

int main() {
    int m, n;
    int caseNo = 1;
    while(scanf("%d %d\n", &m, &n) == 2) {
        for(int i = 0; i < m; i++) {
            scanf("%lld", &a[i]);
        }
        for(int j = 0; j < n; j++) {
            scanf("%lld", &b[j]);
        }

        sort(a, a+m);
        sort(b, b+n);

        int i = m-1, j = n-1;
        int turn = 0;
        while(i >= 0 && j >= 0) {
            if(turn % 2 == 0) {
                play(a, b, i, j);
            } else {
                play(b, a, j, i);
            }
            turn++;
        }
        if(j == -1) {
            printf("Case %d: Takeover Incorporated\n", caseNo);
        } else {
            printf("Case %d: Buyout Limited\n", caseNo);
        }
        caseNo++;
    }
}
