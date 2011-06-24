#include <stdio.h>
#include <string.h>
#include <limits.h>
using namespace std;

#define MAXLEN 31
#define FOR(i,m,n) for(int i = (m); i < (n); ++i)
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef char domain_t[MAXLEN];

enum COST {COPY=0, INSERT=1, DELETE=1, REPLACE=1};

void mutate(domain_t d1, domain_t d2) {
    int cost[MAXLEN][MAXLEN]; 
    memset(cost, 100, sizeof(cost));

    int m = strlen(d1);
    int n = strlen(d2);
    cost[0][0] = 0;
    FOR (i, 0, m) cost[i+1][0] = cost[i][0] + 1; 
    FOR (j, 0, n) cost[j+1][0] = cost[0][j] + 1; 

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n ; ++j) {
            int l  = cost[i+1][j] + INSERT;
            int u  = cost[i][j+1] + DELETE;
            int ul = cost[i][j]   + (d1[i] == d2[j] ? COPY : REPLACE);
            int min;
            min = MIN (l,u);
            min = MIN (min, ul);
            cost[i+1][j+1] = min;
            printf ("%3d ", min);
        }
        printf ("\n");
    }
}

int main() {
    domain_t d1, d2; 
    scanf("%s %s", d1, d2);

    mutate(d1, d2);

    return 0;
}
