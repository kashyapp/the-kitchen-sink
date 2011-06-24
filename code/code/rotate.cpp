#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* rotate a n vector by k in less that n swaps */

inline int min(int a, int b) {
    return a < b ? a : b;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void rotate(vector<int> &v, int k) {
    int g = 0;
//    1 2 3, 4 5 6 7 8 9 0
//    8 9 0, 4 5 6 7 | 1 2 3
//    5 6 7, 4 | 8 9 0
//    4 | 6 7, 5
//    4 | 5 7  6
//    4   5 6 7
//    4 5 6  7 8 9 0 1 2 3
    int i = 0;
    int j = v.size();
    do {
    int l1 = k - i;
    int l2 = j - k;
    int x, y, l;
    l = min(l1, l2);
    for (x = i, y = j - l; x < l + i; ++x, ++y) {
        swap(v[x], v[y]);
        ++g;
    }
    if (l1 < l2) {
        j = j - l;
    } else {
        i = i + l;
        k = j - l;
    }
    } while (i < k);
    cerr << g << " swaps" << endl;
}

int main() {
    int i, k;
    vector<int> v;
    cin >> k;
    while (cin >> i) {
        v.push_back(i);
    }
    rotate(v, k);
    for(int i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}
