/**


  Error codes to output:
    E1: More than 2 children
    E2: Duplicate Tuples
    E3: Cycle present
    E4: Multiple roots
 */
#include <iostream>
#include <set>
#include <utility>
#include <sstream>
#include <cstring>

using namespace std;

bool render(int root, set<int> *all_children, stringstream &os, bool *visited) {
    if (visited[root]) return false;

    bool result = true;
    visited[root] = true;
    char c = root - 1 + 'A';
    os << "(" << c;
    set<int> children = all_children[root];
    for (set<int>::iterator i = children.begin();
            i != children.end();
            i++) {
        result = result && render(*i, all_children, os, visited);
    }
    os << ")";
    return result;
}

int main() {
    char _p, _q, skip;

    bool visited[27];
    int parent[27];
    bool exists[27];

    memset(&visited, 0, sizeof(visited));
    memset(&parent,  0, sizeof(visited));
    memset(&exists,  0, sizeof(visited));
    
    set<int> children[27];
    
    while (cin >> skip >> _p >> skip >> _q >> skip) {
        int p = _p - 'A' + 1;
        int q = _q - 'A' + 1;

        parent[q] = p;
        exists[q] = exists[p] = true;
        
        pair<set<int>::iterator, bool> result = children[p].insert(q);
        if (children[p].size() > 2) {
            cout << "E1" << endl;
            return 0;
        }
        if (!result.second) {
            cout << "E2" << endl;
            return 0;
        }
    }
    int root = 0;
    int numroots = 0;
    for (int i = 1; i < 27; ++i ) {
        if (exists[i] && (parent[i] == 0)) {
            numroots ++;
            root = i;
        }
    }
    if (numroots == 0) {
        cout << "E3" << endl;
        return 0;
    }
    if (numroots > 1) {
        cout << "E4" << endl;
        return 0;
    }

    stringstream output;

    bool good = render(root, children, output, visited);
    if (!good) {
        cout << "E3" << endl;
        return 0;
    }
    cout << output.str() << endl;
    return 0;
}
