#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <algorithm>

using namespace std;


int data[1000];
bool flag[1000];
int temp[1000];

int countinv(int arr[], int n) {
    int inv = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) inv++;
        }
    }
    return inv;
}

int solve() {
    int n;
    cin >> n;
    int inversions = 0;

    for (int i = 0; i < n; i++) {
        cin >> data[i];
        data[i] -= 1;
        flag[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (flag[i]) continue;

        int t = 0;
        int current = i;
        int start = current;
    
        do {
            flag[current] = true;
            temp[t++] = current;
            current = data[current];
        } while (current != start);

        sort(&temp[0], &temp[t]);
        for (int j = 0; j < t; j++) {
            temp[j] = data[temp[j]];
        }
        inversions += countinv(temp, t); 
    }

    return 2 * inversions;
}

int main() {
    int nTest;
    cin >> nTest;
    
    for (int i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ": " << solve() << ".000000" << endl;
    }
}
