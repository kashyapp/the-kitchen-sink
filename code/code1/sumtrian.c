#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define isdigit(c) (c >= '0' && c <='9')

int main() {
    int nTest;
    scanf("%d",&nTest);

    int N;
    unsigned int row[100];

    while (nTest--) {
        scanf("%d", &N);
        memset(row, 0, sizeof(row));
        int i;
        for (i=1; i < N+1; ++i) {
            int curr, temp, prev = 0;
            int j;
            for (j=0; j < i; ++j) {
                curr = 0;
                char c;
                
                do { c = getchar(); } while (!isdigit(c));
                
                do {
                    curr = curr * 10 + c - '0';
                    c = getchar();
                } while (isdigit(c));

                temp = MAX(prev + curr, row[j] + curr);
                prev = row[j];
                row[j] =temp;
            }
        }
        int j, max = 0;
        for (j=0; j < N; ++j) {
            max = MAX(max,row[j]);
        }
        printf("%d\n",max);
    }
}
