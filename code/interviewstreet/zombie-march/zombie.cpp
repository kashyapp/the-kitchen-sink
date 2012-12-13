#include <cmath>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)

typedef vector<vector<int> > graph_t;

inline double incoming(int *split, vector<double> &zombie_from, const vector<int> &edges) {
  double t = 0;
  FOR(i, edges.size()) {
    int from = edges[i];
    t += zombie_from[from] / split[from];
  }
  return t;
}

void solve(int node_count, int clocks, const graph_t &edges, vector<double> &zombie_from) {
  int split[node_count];
  vector<double> zombie_to(node_count);

  FOR(i, node_count) {
    split[i] = edges[i].size();
    assert(split[i]);
  }

  FOR(i, clocks) {
    double change = 0;
    FOR(j, node_count) {
      double prev = zombie_to[j];
      zombie_to[j] = incoming(split, zombie_from, edges[j]);
      change += abs(zombie_to[j] - prev);
    }
    //cerr << std::fixed << setprecision(10) << change << endl;
    swap(zombie_from, zombie_to);

    if (change < 0.01) break;
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
    graph_t edges(N);
    vector<double> zombies(N);

    FOR(i, M) {
      int p, q;
      cin >> p >> q;
      edges[p].push_back(q);
      edges[q].push_back(p);
    }

    FOR(i, N) {
      cin >> zombies[i];
    }

    solve(N, K, edges, zombies);
  }
  return 0;
}
