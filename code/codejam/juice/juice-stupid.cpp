#include <iostream>
#include <cstring>
using namespace std;

typedef short row_t[3];

bool enough(row_t juice, row_t needs) {
    return juice[0] >= needs[0]
        && juice[1] >= needs[1]
        && juice[2] >= needs[2];
}

bool topup(row_t juice, row_t needs) {
    int sum = 0;
    for (int i=0; i<3; i++) {
        if (needs[i] > juice[i]) {
            juice[i] = needs[i];
        }
        sum += juice[i];
    }
    return sum <= 10000;
}

void copy(row_t to, row_t from) {
    memcpy(to, from, sizeof(row_t));
}

void foo(int *max, int cursize, int n, int i, row_t juice, row_t data[]) {
    //cerr << n << i << endl;
    if (i >= n) { // terminate
        if (cursize > *max) {
            *max = cursize;
        }
        return;
    } 
    if (enough(juice, data[i])) {
        foo(max, cursize + 1, n, i + 1, juice, data);
    } else {
        foo(max, cursize, n, i + 1, juice, data); // without

        //cerr << "before " << juice[0] << " "  << juice[1] << " " << juice[2] << endl;
        row_t backup;
        copy(backup, juice);
        if (topup(juice, data[i])) {
            //cerr << "after  " << juice[0] << " "  << juice[1] << " " << juice[2] << endl;
            foo(max, cursize + 1, n, i + 1, juice, data); // with
        }
        //cerr << "during " << juice[0] << " "  << juice[1] << " " << juice[2] << endl;
        copy(juice, backup);
        //cerr << "after  " << juice[0] << " "  << juice[1] << " " << juice[2] << endl;
    }
}

int solve() {
    int n;
    cin >> n; // number of people

    row_t *data = new row_t[n];

    int m = n;
    while (n--) {
        row_t &r = data[n];
        cin >> r[0] >> r[1] >> r[2];
    }

    row_t juice = {0, 0, 0};
    int max = 0;
    foo (&max, 0, m, 0, juice, data);

    delete [] data;
    
    return max;
}

int main() {
    int nTest;
    cin >> nTest;
    for (int iTest = 1; iTest <= nTest; iTest++) {
        int n = solve();
        cout << "Case #" << iTest << ": " << n << endl;
    }
}
