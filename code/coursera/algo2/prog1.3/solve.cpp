#include <cassert>
#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)

typedef size_t vertex_t;

struct Edge {
  vertex_t lr;
  int w;
  vertex_t l, r;
  bool entered;

  Edge() {
    Edge(0, 0, 0);
  }

  Edge(vertex_t _l, vertex_t _r, int _w) : 
    lr(_l + _r), 
    w(_w), 
    entered(false) 
  {
  }

  vertex_t other(vertex_t l) const {
    return lr - l;
  }

  bool enter(vertex_t _l) {
    if (entered) return false;
    entered = true;
    l = _l;
    r = other(l);
    return true;
  }
};

struct EdgeCompare {
  bool operator() (const Edge *l, const Edge *r) {
    if (l == r) return false;

    assert(l->entered);
    assert(r->entered);

    if (l->w != r->w) return l->w < r->w;
    if (l->l != r->l) return l->l < r->l;
    if (l->r != r->r) return l->r < r->r;

    return false;
  }
};

int main() {
  int V, E;
  cin >> V >> E;

  vector<list<Edge*> > graph(V+1);
  Edge *edges = new Edge[E];

  FOR(i, E) {
    int l, r, w;
    cin >> l >> r >> w;
    edges[i] = Edge(l, r, w);
    graph[l].push_back(&edges[i]);
    graph[r].push_back(&edges[i]);
  }

  /* until no more vertices left to discover
   * sorted set of crossing edges
   * pick cheapest and add to tree
   * add newly discovered edges to the above set
   */

  set<Edge*, EdgeCompare> cross;
  set<vertex_t> discovered;

  Edge fake(0, 1, 0);
  fake.enter(0);
  cross.insert(&fake);

  int weight = 0;
  while(discovered.size() != V) {

    set<Edge*>::iterator i = cross.begin();
    Edge *selected;
    do {
      selected = *i;
      cross.erase(i++);
      cerr << "removing: " << selected->l << " " << selected->r << " " << selected->w << endl;
    } while(discovered.count(selected->r));

    cerr << selected->l << " " << selected->r << " " << selected->w << endl;

    weight += selected->w;
    vertex_t v = selected->r;

    discovered.insert(v);

    for(list<Edge*>::iterator i = graph[v].begin();
        i != graph[v].end();
        i++) {
      Edge *e = *i;
      if (e->enter(v) && discovered.count(e->r) == 0) {
        cross.insert(e);
        cerr << "adding: " << e->l << " " << e->r << " " << e->w << endl;
      }
    }
  }

  cout << weight << endl;
  return 0;
}
