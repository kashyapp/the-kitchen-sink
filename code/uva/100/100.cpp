#include <vector>
#include <iostream>
#include <cstring>
#include <stack>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

map<int, int> table;

int f(int curr) {
  stack<int> s;

  while(!table[curr]) {
    if (curr%2) {
      curr = 3 * curr + 1;
    } else {
      curr = curr / 2;
    }
    s.push(curr);
  }

  int count = table[curr];
  while(!s.empty()) {
    curr = s.top(); s.pop();
    table[curr] = count++;
  }

  return count;
}

int solve(int m, int n) {
  int max = 1;
  for(int i = m; i <= n; ++i) {
    int current = f(i);
    if (current > max) max = current;
  }

  return max;
}

int main() {
  int m, n;

  table[1] = 1;

  while(cin >> m >> n) {
    cout << m << " " << n << " ";
    if (m > n) swap(m, n);
    cout << solve(m, n) << endl;
  }
  return 0;
}
