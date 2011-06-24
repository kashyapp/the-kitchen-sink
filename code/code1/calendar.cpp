#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

int main() {
    int i,j;
    vector<pair<int, int>> calendar;

    bool b = false;
    pair<int, int> p;
    while (cin >> i) {
        if (b) {
            p = make_pair(j, i);
            v.push_back(p);
        } else {
            j = i;
        }
    }

    return 0;
}


