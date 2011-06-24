//spoj FCTRL
// 2010-12-13
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int fctrl2(int m) {
    const int fives[] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
    const int fifes[] = {0, 1, 6, 31, 156, 781, 3906, 19531, 97656, 488281, 2441406, 12207031, 61035156};

    int count = 0;

    for (int i = -1 + sizeof(fives)/sizeof(int); m > 0 ; ) {
        if (fives[i] <= m) {
            count += fifes[i];
            m -= fives[i];
        } else {
            --i;
        }
    }
    return count;
}

int fctrl(int m) {
    const int fives[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
    int count = 0;

    for (int i=0; fives[i] <= m && i < sizeof(fives)/sizeof(int); ++i) {
        count += m/fives[i];
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    /*
    for (int i = 5, j = 1; i < 1000000000; j += i, i *= 5) {
        printf("%12d,%12d,\n",i,j);
    }
    */

    int p;
    while (n--) {
        scanf("%d", &p);
        printf("%d\n", fctrl2(p));
    }
}
