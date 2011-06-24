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
#define WIN 1
#define LOSS -1
#define NP 0

char line[101];
int data[100][100];
double rpi[100];
int win[100];
int total[100];
double wp[100];
double owp[100];
double oowp[100];

void reset() {
    memset(rpi, 0, sizeof(rpi));
    memset(win, 0, sizeof(win));
    memset(total, 0, sizeof(total));
    memset(wp, 0, sizeof(wp));
    memset(owp, 0, sizeof(owp));
    memset(oowp, 0, sizeof(oowp));
}

void solve() {
    reset();

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> line;
        for (int j = 0; j < t; ++j) {
            switch (line[j]) {
                case '0':
                    data[i][j] = LOSS;
                    total[i]++;
                    break;
                case '1':
                    data[i][j] = WIN;
                    win[i]++;
                    total[i]++;
                    break;
                default:
                    data[i][j] = NP;
            }
        }
        wp[i] = (double)win[i]/total[i];
    }
    for (int i = 0; i < t; ++i) {
        double sum = 0;
        int num = 0;
        for (int j = 0; j < t; ++j) { 
            if (data[i][j] == NP) continue;
            ++num;
            if (data[i][j] == WIN) {
                sum += (double)win[j]/(total[j] - 1);
            } else if (data[i][j] == LOSS) {
                sum += (double)(win[j] - 1)/(total[j] - 1);
            }
            cerr << win[j] << " " << total[j] << endl;
        }
        cerr << endl;
        owp[i] = (double)sum/num;
    }

    for (int i = 0; i < t; ++i) { 
        double sum = 0;
        int num = 0;
        for (int j = 0; j < t; ++j) { 
            if (data[i][j] == NP) continue;
            ++num;
            sum += owp[j];
            cerr << owp[j] << " ";
        }
        oowp[i] = sum/num;
        cerr << oowp[i] << ' ' << i << endl;
        cerr << endl;
    }

    for (int i = 0; i < t; ++i) {
        printf("%.7f\n",wp[i] * .25 + owp[i] * 0.50 + oowp[i] * .25);
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
