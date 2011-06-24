#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

// the graph structure
typedef map<char,set<char> > Graph;

// to print out a graph
ostream& operator<<(ostream& o, const Graph &g){
    for(Graph::const_iterator i = g.begin(); 
            i!=g.end(); 
            i++){
        o << i->first << " -> ";
        for(set<char>::const_iterator j = i->second.begin(); 
                j!= i->second.end(); 
                j++){
            o << *j << ", ";
        }
        o << endl;
    }
    return o;
}

// the node of the Trie
class Node {
    public:
        char value;
        Node* sibling;
        Node* child;
        Node(char s) : value(s), sibling(NULL), child(NULL) {}
        Node();
};

// to print out a trie
ostream& operator<<(ostream& o, Node* n){
    if (n!=NULL){
        o << "(";
        o << n->value;
        o << n->child;
        o << ")";
        o << n->sibling;
    }
    return o;
}

/* given a dictionary in vector dict, 
 * returns a trie constructed from the dictionary
 * graph is constructed from the sibling information in the tree
 */
Node* constructTrie(vector<string> const &dict, Graph &graph) {
    Node* root = new Node('.');
    for (vector<string>::const_iterator i = dict.begin(); i != dict.end(); i++) {
        const string &word = *i;
        Node* current = root;
        for (int j = 0; j < word.length(); j++) {
            char value = word[j];
            if (current->child == NULL) {
                current->child = new Node(value);
            }
            current = current->child;
            while (current->value != value) {
                if (current->sibling == NULL) {
                    current->sibling = new Node(value);
                    graph[current->value].insert(value);
                }
                current = current->sibling;
            }
        }
    }
    return root;
}

// does a dfs and then returns a string constructed with the nodes in the 
// reverse finishing order
//
// takes a graph and a start node
string dfs(Graph &g, char start) {
   string ret;
   stack<char> s;
   enum Color { WHITE, GREY, BLACK} ;
   map<char,int> color;

   s.push(start);
   do {
       char current = s.top();
       if (color[current] == WHITE) {
           color[current]=GREY;
           for (set<char>::const_iterator i = g[current].begin();
                   i != g[current].end();
                   i++) {
               if (color[*i] != BLACK) {
                   s.push(*i);
               }
           }
       }
       else if (color[current] == GREY) {
           color[current] = BLACK;
           ret.push_back(current);
           s.pop();
       } 
       else {
           s.pop();
       }
   } while (!s.empty());

   reverse(ret.begin(),ret.end());

   return ret; 
}

// takes a dictionary of words known to be in sorted order and gives the 
// collating order of the alphabet
string rareorder(vector<string> const &dict) {
    string retval("you are a failure!");
    Graph graph;
    Node* tree = constructTrie(dict, graph);
    //cerr << tree << endl;
    //cerr << graph << endl;

    if(tree->child != NULL)
        retval = dfs(graph,tree->child->value);  

    return retval;
}

// main, duh!
int main() {
    string s;
    vector<string> dict;
    while (cin >> s && s != "#") {
        dict.push_back(s);
    }
    cout << rareorder(dict) << endl;
    return 0;
}
