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

char data[50][51];

#define UL 0
#define UR 1
#define LL 2
#define LR 3

void solve() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> data[i];
    }
    for (int i = 0; i < (r-1); ++i) {
        for (int j = 0; j < (c -1) ; ++j) {
            if (data[i][j] == '.' || data[i][j] != '#') continue;
            if (data[i][j+1] == '#' && data[i+1][j+1] =='#' && data[i+1][j] =='#') {
                data[i][j] = '/';
                data[i][j+1] = '\\';
                data[i+1][j] = '\\';
                data[i+1][j+1] = '/';
            } else {
                cout << "Impossible" << endl;
                return;
            }
        }
    }

    for (int j = 0; j < c; ++j) {
        if (data[r-1][j] == '#') {
                cout << "Impossible" << endl;
                return;
        }
    }
    for (int i = 0; i < r; ++i) {
        if (data[i][c-1] == '#') {
                cout << "Impossible" << endl;
                return;
        }
    }
    for (int i = 0; i < r; ++i) {
        cout << data[i] << endl;
    }

}

int main() {
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ":" << endl;
        solve();
    }
}
