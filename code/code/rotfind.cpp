#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int find(vector<int> &haystack, int needle, int begin, int end) {
    cerr << begin << " " << end << endl;
    assert(end >= begin);
    if (end == begin) {
        if (haystack[begin] == needle) {
            return begin;
        } else {
            return -1;
        }
    } else {
        int mid = (end + begin)/2;
        int a1, a2, b1, b2;
        if (haystack[begin] < haystack[mid]) {
            a1 = begin; a2 = mid; b1 = mid + 1; b2 = end;
        } else {
            a1 = mid + 1; a2 = end; b1 = begin; b2 = mid;
        }
        if (a1 <= a2 && needle >= haystack[a1] && needle <= haystack[a2]) {
            return find(haystack, needle, a1, a2);
        } else if (b1 <= b2) {
            return find(haystack, needle, b1, b2);
        } else {
            return -1;
        }
    }
}

int main() {
    int i, j;
    vector<int> v;
    cin >> j;
    while(cin >> i) {
        v.push_back(i);
    }
    cout << find(v, j, 0, v.size()-1) << endl; 
}
