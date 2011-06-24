#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int gcd(int y) {
    int x = 100;
    int r = x % y;

    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }

    return y;
}

void solve() {
}

int main() {
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
