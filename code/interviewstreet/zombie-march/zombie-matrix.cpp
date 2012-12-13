#include <cmath>
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include "matrix.h"
#include <valarray>

using namespace std;
using namespace kashyap;

#define FOR(i, n) for(int i = 0; i < n; ++i)

void print(valarray<double> &zombies) {
  vector<double> zombie_from(zombies.size());
  FOR(i, zombies.size()) {
    zombie_from[i] = zombies[i];
  }
  sort(zombie_from.rbegin(), zombie_from.rend());
  FOR(i, 5) {
    cout << rint(zombie_from[i]) << " ";
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, M, K;
    cin >> N >> M >> K;

    matrix<double> graph(N);
    vector<int> splits(N, 0);

    FOR(i, M) {
      int p, q;
      cin >> p >> q;
      graph(p, q) = 1;
      graph(q, p) = 1;
      splits[p]++;
      splits[q]++;
    }

    matrix<double> split_matrix(N);
    FOR(i, N) {
      split_matrix(i, i) = 1.0 / splits[i];
    }

    matrix<double> weighted_graph = graph * split_matrix;

    /*
    cerr << graph;
    cerr << "---" << endl;
    cerr << split_matrix;
    cerr << "---" << endl;
    cerr << graph * split_matrix;
    cerr << "---" << endl;
    cerr << (weighted_graph);
    */
    cerr << (weighted_graph);

    valarray<double> zombies(N);
    FOR(i, N) {
      cin >> zombies[i];
    }

    valarray<double> result = (weighted_graph ^ K) * zombies;

    print(result);
  }
  return 0;
}
