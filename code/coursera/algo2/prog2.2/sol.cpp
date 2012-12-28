#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std::tr1;
using namespace std;

typedef unsigned int node_t;

void slurp(unordered_map<node_t, int> &nodes, int &num_nodes, int &num_bits) {
  cin >> num_nodes >> num_bits;

  for(int i=0; i < num_nodes; ++i) {
    unsigned int num = 0;
    for(int j=0; j < num_bits; ++j) {

      num <<= 1;
      unsigned int c;
      cin >> c;
      num |= c;
    }
    nodes[num]=i;
  }
}

void populate_candidates(node_t node, node_t *candidates, int num_bits) {
  unsigned int toggle;
  for (int i = 0, toggle = 1; i < num_bits; ++i, toggle <<= 1) {
    candidates[i] = node ^ toggle;
  }
  for (int j = 0; j < num_bits; ++j) {
    for (int k = 0, toggle = 1; k < num_bits; ++k, toggle <<= 1) {
      int index = num_bits * (1+j) + k;
      candidates[index] = candidates[j] ^ toggle;
    }
  }
}

class disjoint_set {
  int num_sets;
  int sz;
  int *parents;
  int *sizes;
  disjoint_set() {
  }

  public:
  ~disjoint_set() {
    delete[] parents;
  }

  disjoint_set(int size) {
    sz = size;
    num_sets = size;
    parents = new int[size];
    sizes = new int[size];

    for (int i=0; i < size; ++i) {
      parents[i] = i;
      sizes[i] = 1;
    }
  }

  int find(int p) {
    if (parents[p] != p) {
      parents[p] = find(parents[p]);
    }
    return parents[p];
  }

  void merge(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    if (u_root != v_root) {
      cerr << "merge: " << u << " " << v << endl;
      parents[u_root] = v_root;
      num_sets--;
      sizes[v_root] += sizes[u_root];
    }
  }

  int size() const {
    for (int i=0; i < sz; ++i) {
      if (parents[i] == i) {
        cerr << "s: " << sizes[i] << endl;
      }
    }
    return num_sets;
  }
};

int main() {
  int num_nodes, num_bits;
  unordered_map<node_t, int> nodes;

  slurp(nodes, num_nodes, num_bits);
  disjoint_set dj(nodes.size());

  for (unordered_map<node_t, int>::iterator i = nodes.begin();
      i != nodes.end();
      ++i) {
    int num_candidates = num_bits * (num_bits + 1);
    node_t candidates[num_candidates];
    populate_candidates(i->first, candidates, num_bits);

    for (int j = 0; j < num_candidates; ++j) {
      node_t candidate = candidates[j];
      if (candidate != i->first && nodes.count(candidate)) {
        int u = i->second;
        int v = nodes[candidate];
        dj.merge(u, v);
      }
    }
  }

  cout << dj.size() << endl;

  return 0;
}
