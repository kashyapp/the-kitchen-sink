#include <iostream>
using namespace std;
/**
 * T <= 15
 * Ai, Bi <= 10^4
 */

#define W 10000

int A[W], B[W];

int solve() {
    int count = 0;
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool a = (A[i] - A[j]) > 0;
            bool b = (B[i] - B[j]) > 0;
            count += a^b;
            bool x = a^b;
            //cout << i << " " << j << " " << x << endl;
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}
