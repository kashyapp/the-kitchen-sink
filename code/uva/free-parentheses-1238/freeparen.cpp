#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>

using namespace std;

void join(set<int> *result, const set<int> &lft, int oper, const set<int> &rgt) {
  for(set<int>::iterator i = lft.begin(); i != lft.end(); i++) {
    for(set<int>::iterator j = rgt.begin(); j != rgt.end(); j++) {
      int ans = (*i) + oper * (*j);
      result->insert(ans);
    }
  }
}

map<pair<int, int>, set<int> > table;
int hits, misses;

const set<int> rec(const vector<int> &expr, int start, int n) {
  pair<int, int> key = make_pair(start, n);
  if (table.find(key) != table.end()) {
    hits++;
    return table[key];
  }
  misses++;

  set<int> result;

  for(int i = 0; i < n; ++i) {
    int oper = expr[start + 2*i+1];
    const set<int> &lft = rec(expr, start, i);
    const set<int> &rgt = rec(expr, start + 2*i+2, n-i-1);
    join(&result, lft, oper, rgt);
  }

  if (n == 0) {
    result.insert(expr[start]);
  }

  table[key] = result;

  return result;
}

int solve(vector<int> expr, int n) {
  table.clear();
  hits = misses = 0;

  int result = rec(expr, 0, n).size();
  cerr << "hit/miss " << hits << "/" << misses << endl;

  return result;
}

int main() {
  char str[200];

  while(cin.getline(&str[0], 200)) {
    vector<int> members;

    char *z = &str[0];
    char c;
    int n = 0;
    while ((c = *z) != '\0') {
      z++;
      switch(c) {
        case ' ':
          break;
        case '-':
          members.push_back(-1);
          n++;
          break;
        case '+':
          members.push_back(1);
          n++;
          break;
        default:
          z--;
          members.push_back(strtol(z, &z, 10));
      }
    }

    cout << solve(members, n) << endl;
  }

  return 0;
}
