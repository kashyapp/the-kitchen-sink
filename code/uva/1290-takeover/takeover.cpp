#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

void read(int m, vector<int> &M) {
  int p;
  while (m--) {
    cin >> p;
    M.push_back(p);
  }
  sort(M.begin(), M.end());
}

template<typename I, typename E>
bool f(I ms, E m, I ns, E n) {
  if (ms == m.end()) return false;
  if (ns == n.end()) return true;

  if (ms != m.end()) {
  }
}

int solve(int m, int n) {
  vector<int> M, N;
  read(m, M);
  read(n, N);

  

  return 1;
}

int main() {
  int m, n;

  char const *result[2] = {"Takeover Incorporated", "Buyout Limited"};

  for (int i=1; cin >> m >> n; i++) {
    int r = solve(m, n);
    cout << "Case " << i << ": " << result[r] << endl;
  }
  return 0;
}
