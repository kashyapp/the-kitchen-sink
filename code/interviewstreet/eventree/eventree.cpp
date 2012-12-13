#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct node {
  vector<node> children;
};

typedef vector< vector<int> > tree_t;

bool foo(int &counter, tree_t &tree, int root) {
  bool result = 1;
  vector<int> &children = tree[root];
  for(int i = 0; i < children.size(); ++i) {
    bool odd = foo(counter, tree, children[i]);
    counter += !odd;
    result ^= odd;
  }
  return result;
}

int main() {
  int V, E;
  cin >> V >> E;
  tree_t alist(V+1);
  while(E--) {
    int c, p;
    cin >> c >> p;
    alist[p].push_back(c);
  }
  int counter = 0;
  assert(foo(counter, alist, 1) == 0);
  cout << counter << endl;

  return 0;
}
