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

struct point {
    double start;
    double end;
    double time;

    point() {
    }

    point(int m, int l, int d) {
        time = (double)(m-1)*d/2.0;
        double radius = (double) m * (double) d / 2.0; 
        start = l - radius;
        end = l + radius;
    }
};

void foo(const point &p) {
    cerr << p.start << " " << p.end << " " << p.time << endl;
}

void solve() {
    double tt = 0;
    double last = -99999999;

    int n;
    int d;
    cin >> n >> d;

    for (int i = 0; i < n; ++i) {
        int m, l;
        cin >> l >> m;
        point current(m, l, d);

        if (last <= current.start) {
            tt = max(tt, current.time);
            last = current.end;
        } else {
            double move = last - current.start;

            if (tt > current.time) {
                
                double tdelta = tt - current.time;
                if (tdelta > move) {
                    tdelta = move;
                }

                move -= tdelta;
                current.start += tdelta;
                current.end += tdelta;

            } else /* tt < current.time */ {

                double tdelta = current.time - tt;
                if (tdelta > move) {
                    tdelta = move;
                }
                
                move -= tdelta;
                last -= tdelta;

                tt = current.time;
            }
            tt += move/2.0;
            last = current.end + move/2.0;
        }
    }
    
    printf("%.7f\n", tt);
}

int main() {
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
