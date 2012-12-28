#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#define NUM_CLUSTERS 4
using namespace std;

struct vertex_t {
  vertex_t *parent;
  size_t rank;
};

struct Edge {
  vertex_t *u;
  vertex_t *v;

  int weight;

  bool operator< (const Edge& other) const {
    return weight < other.weight;
  }
};

vertex_t *offset;

#ifndef SLOW
vertex_t *find(vertex_t *needle) {
  return (needle == needle->parent)
    ? needle 
    : needle->parent = find(needle->parent)
    ;
}

#else

vertex_t *find(vertex_t *needle) {
#ifdef DEBUG
  cerr << "... " << needle - offset;
#endif
  while (needle != needle->parent) {
    needle = needle->parent;
#ifdef DEBUG
    cerr << " -> " << needle - offset;
#endif
  }
#ifdef DEBUG
  cerr << endl;
#endif
  return needle;
}

#endif

void merge(vertex_t *u, vertex_t *v) {
  //cerr << "ranks: " << u->rank << " " << v->rank << endl;
  if (u->rank > v->rank) {
    v->parent = u;
    u->rank ++;
  } else {
    u->parent = v;
    v->rank ++;
  }
}

int main() {
  int v;
  cin >> v;

  int num_sets = v;

  int e = v * (v-1) / 2;

  vertex_t vertices[v+1];
  offset = &vertices[0];
  for (int i = 1; i <= v; ++i) {
    // each is its own set
    vertices[i].parent = &vertices[i];
    vertices[i].rank = 0;
  }

  Edge *edges = new Edge[e];

  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i].weight = w;
    edges[i].u = &vertices[u];
    edges[i].v = &vertices[v];
  }

  sort(edges, edges + e);

  for (int i = 0; i < e; ++i) {
    Edge &e = edges[i];
    vertex_t *v_root = find(e.v);
    vertex_t *u_root = find(e.u);
    if (v_root != u_root) {
      cerr << e.weight << " " << num_sets << endl;

      if (num_sets == NUM_CLUSTERS) {
        cout << "****** result: " << edges[i].weight << endl;
        break;
      }

      merge(v_root, u_root);
      num_sets--;

    } else {
#ifdef DEBUG_SKIP
      cerr << "skipping " << (e.v - offset) << " " << (e.u - offset) << endl;
#endif
    }
  }

  return 0;
}
