#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

typedef vector<size_t> tt;


class Solver {
    size_t nVessel;
    set<tt> visited;
    tt &capacity;
    tt &target;

    void insert(const tt &mugs) {
        if (visited->find(mugs) != visited->end()) {
            visited->insert(mugs);
        }
    }

    void fill(const tt current, size_t to) {
        tt mugs(current);
        mugs[to] = capacity[to];
        insert(mugs);
    }

    void empty(const tt current, size_t from) {
        tt mugs(current);
        mugs[from] = 0;
        insert(mugs);
    }

    void fill(const tt current, size_t to) {
    }

    void pour(const tt current, size_t from, size_t to) {
        tt mugs(current);

        int remainderTo = capacity[to] - current[to];

        int transfer = 0;
        if (current[from] <= remainderTo) {
            transfer = current[from];
        } else {
            transfer = remainderTo;
        }

        mugs[from] -= transfer;
        mugs[to]   += transfer;

        insert(mugs);
    }

    public:
    Solver(size_t _nVessel, const tt &_capacity, const tt &_target):
        nVessel(_nVessel),
        capacity(_capacity),
        target(_target) {}

    void solve() {
        tt start(nVessel, 0);
        for (int i=0; i<nVessel; ++i) {
            for(int j=i+1; j<nVessel; ++j) {
                pour(start, i, j);
                pour(start, j, i);
            }
            fill(start, i);
            empty(start, i);
        }
    }
};

int main() {
    int nVessel;
    cin >> nVessel;

    tt capacity(nVessel);
    for (int i=0; i<nVessel; ++i) {
        cin >> capacity[i];
    }

    tt target(nVessel);
    for (int i=0; i<nVessel; ++i) {
        cin >> target[i];
    }

    Solver(nVessel, capacity, target).solve();

    return 0;
}
