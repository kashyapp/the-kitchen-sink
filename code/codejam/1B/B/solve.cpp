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

long dist[1000000];

void solve() {
    long L, t, N, C;
    cin >> L >> t >> N >> C;

    for (long i = 0; i < C; ++i) {
        cin >> dist[i];
    }

    map<long, long> counts;
    for (long i = 0; i < C; ++i) {
        counts[C] = 0;
    }

    long worst = 0;
    for (long i = 0; i < N; ++i) {
        long current = dist[i%C];
        ++counts[current];
        //cerr << current << " " << counts[current] << endl;
        worst += dist[i%C] * 2;
    }
    cerr << "worst " << worst << endl;

    if (worst <= t) {
        cout << worst << endl;
        return;
    }

    long buildDist = t/2;
    long n = 0;
    while(1) {
        long current = dist[n%C];
        counts[current]--;
        if (buildDist < current) {
            buildDist = current - buildDist;
            break;
        }
        buildDist -= current;
        n++;
    }

    cerr << "build " << buildDist << endl; 
    sort(&dist[0], &dist[C]);

    long currentDist = C-1;
    for (long i = 0; i < L; ++i) {
        while (counts[dist[currentDist]] == 0) {
            currentDist--;
        }
        cerr << "current " << currentDist << " " << dist[currentDist] << endl;
        if (buildDist > dist[currentDist]) {
            cerr << "sdbuild " << buildDist << endl; 
            worst -= buildDist;
            buildDist = 0;
        } else {
            counts[dist[currentDist]]--;
            worst -= dist[currentDist];
        }
    }

    cout << worst << endl;
}

int main() {
    long nTest;
    cin >> nTest;

    for (long i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
