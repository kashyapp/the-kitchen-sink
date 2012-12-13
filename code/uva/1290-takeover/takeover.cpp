#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef unsigned long long sub_size_t;

void read(int m, vector<sub_size_t> &M) {
  sub_size_t p;
  while (m--) {
    cin >> p;
    M.push_back(p);
  }
  sort(M.rbegin(), M.rend());
}

template <typename I>
void print(I start, I end) {
  cerr << "[";
  while(start != end) {
    cerr << *start << " ";
    start++;
  }
  cerr << "]" << endl;
}

template <typename I>
int step(I &mi, const I &m_end, I &ni, const I &n_end, int m_id, int n_id, bool &prevOpMerge) {
  int result = -1;
  if (*mi > *ni) {
    if (prevOpMerge) return m_id;
    ni++;
    prevOpMerge = false;
  } else {
    sub_size_t temp = *mi;
    mi++;
    prevOpMerge = true;
    if (mi != m_end) {
      *mi += temp;
    }
  }

  if (mi == m_end) {
    result = n_id;
  }
  if (ni == n_end) {
    result = m_id;
  }

  return result;
}

int solve(int m, int n) {
  vector<sub_size_t> M, N;
  read(m, M);
  read(n, N);

  vector<sub_size_t>::iterator mi = M.begin();
  vector<sub_size_t>::iterator ni = N.begin();

  int result;
  bool prevOpMerge = false;
  while(true) {
    result = step(mi, M.end(), ni, N.end(), 0, 1, prevOpMerge);
    if (result != -1) break;

    result = step(ni, N.end(), mi, M.end(), 1, 0, prevOpMerge);
    if (result != -1) break;
  }

  return result;
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
