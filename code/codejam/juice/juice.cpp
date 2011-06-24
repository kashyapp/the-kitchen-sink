#include <iostream>
#include <cstring>

using namespace std;

int A[5000], B[5000], C[5000];
int X[10001], Y[10001];

void makejuice(int m, int c, int target, int *max) {
    memset(X, 0, sizeof(X));
    memset(Y, 0, sizeof(Y));
    for (int i = 0; i < m; i++) {
        if (C[i] <= c && A[i] + B[i] <= target) {
            X[A[i]]++;
            Y[B[i]]++;
        }
    }

    int count = X[0];
    if (count > *max) *max = count;

    for (int a = 1; a <= target; a++) {
        int b = target - a;
        count = count + X[a] - Y[b+1];
        if (count > *max) *max = count;
    }
}

int solve() {
    int count = 0;
    int m;
    cin >> m; // n persons
    
    for (int i = 0; i < m; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    for (int i = 0; i < m; i++) {
        int target = 10000 - C[i];
        makejuice(m, C[i], target, &count); 
    }

    /*
    for (int c = 0; c <= 10000; c++) {
        int target = 10000 - c;
        makejuice(m, c, target, &count); 
    }
    */

    return count;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}
