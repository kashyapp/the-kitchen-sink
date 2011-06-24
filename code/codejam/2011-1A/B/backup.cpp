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

point data[200];

void foo(const point &p) {
    cerr << p.start << " " << p.end << " " << p.time << endl;
}

point recurse(int i, int j) {
    cerr << " > " << i << " " << j << endl;
    if (i == j) {
        return data[i];
    } else {
        point left, right;
        if (j == i+1) {
            left = data[i];
            right = data[j];
        } else {
            int middle = (j+i)/2;
            left = recurse(i, middle);
            right = recurse(middle+1, j);
        }

        cerr << "^^\n";
        foo(left);
        foo(right);
        cerr << "--\n";
        point result;
        if (left.end > right.start) {
            double move = left.end - right.start;
            if (left.time > right.time) {
                double delta = left.time - right.time;
                if (delta > move) {
                    delta = move;
                }
                move -= delta;
                right.start += delta;
                right.end += delta;
            } else {
                double delta = right.time - left.time;
                if (delta > move) {
                    delta = move;
                }
                move -= delta;
                left.start -= delta;
                left.end -= delta;
            }

            result.start = left.start - (double)move/2.0;
            result.end = right.end + (double)move/2.0;
            result.time = (double)move/2.0 + max(left.time, right.time);
        } else {
            result.start = left.start;
            result.end = right.end;
            result.time = max(left.time, right.time);
        }
        cerr << " < " << i << " " << j << endl;
        return result;
    }
}

void solve() {
    int n;
    int d;
    cin >> n >> d;
    int m, l;
    for (int i = 0; i < n; ++i) {
        cin >> l >> m;
        data[i] = point(m, l, d);
        //cerr << data[i].start << " " << data[i].end << " " << data[i].time << endl;
    }
    
    point result = recurse(0, n-1);

    printf("%.7f\n",result.time);
}

int main() {
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
