#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
  int left;
  int right;
};

int solve(vector<node> &nodes, int index, int last_painted) {
  if (last_painted == 10000) {
    return 0;
  }

  if (nodes.size() == index) {
    return -1;
  } 

  if (last_painted + 1 < nodes[index].left) {
    return -1;
  }

  int excluded = solve(nodes, index + 1, last_painted);
  int included = solve(nodes, index + 1, nodes[index].right);

  if (included < 0) {
    return excluded;
  }

  if (excluded < 0) {
    return 1 + included;
  } 

  if (1 + included > excluded) {
    return excluded;
  } else {
    return 1 + included;
  }

  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<node> nodes;

  while (n--) {
    node n;
    cin >> n.left;
    cin >> n.right;
    nodes.push_back(n);
  }

  int answer = solve(nodes, 0, 0);
  if (answer <= 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << answer << endl;
  }
  return 0;
}
