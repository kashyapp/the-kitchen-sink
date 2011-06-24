#include <algorithm>
#define isdigit(c) (c >= '0' && c <='9')
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using std::sort;
typedef struct boo {int x;int pos;} boo;

bool boocmp(boo a, boo b) {
    if (a.x == b.x)
        return (a.pos > b.pos);
    else
        return (a.x > b.x);
}

inline int readint() {
    int curr = 0;
    int sign = 1;
    char c;

    /*
    scanf("%d",&curr);
    return curr;
    */

    do { c = getchar(); } while (!isdigit(c) && c != '-');

    if (c == '-') { c = getchar(); sign = -1; }

    do {
        curr = curr * 10 + c - '0';
        c = getchar();
    } while (isdigit(c));

    return sign * curr;
}

int main() {
    int N = readint();

    boo *arr = (boo*) malloc(N * sizeof(boo));

    for (int i = 0; i < N; ++i) {
        arr[i].x = readint();
        arr[i].pos = i;
    }

    sort(arr, arr+N, boocmp);

    int max = 0;
    int lspan = -2;
    for(int i = 0; i < N; ++i) {
        int span = max - arr[i].pos;
        if (span > 0) {
            lspan = MAX(lspan, span);
        } else {
            max = arr[i].pos;
        }
    }
    
    printf("%d\n",lspan+1);

    return 0;
}
