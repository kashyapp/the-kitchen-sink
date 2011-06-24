#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

class Bar;

//template <class T>
class Graph{
public:
    enum colours{WHITE,GREY,BLACK};
    struct Node{
        void fuck(Bar &boo);
        vector<Node *> adj;
        int value;
        colours colour;
        Node():colour(WHITE){}
    };
private:
    vector<Node> nodes;
    int numNodes;
public:
    Graph(const int numNodes, const vector<pair<int, int> > &edges)
        :numNodes(numNodes){
            nodes.resize(numNodes);
            for_each(nodes.begin(),nodes.end(),populateNode(1));
            for_each(edges.begin(),edges.end(),populateEdge(nodes));
        }
    void bfs();
    void dfs();
private:
    struct populateEdge{
        void operator()(const pair<int,int> &p){
            Node &f = nodes[p.first-1];
            Node &t = nodes[p.second-1];
            f.adj.push_back(&t);
            //cout << "[" << p.first << ", " << p.second << "]" << endl;
            cout << "[" << f.value << ", " << t.value << "]" << endl;
        }
        populateEdge(vector<Node> &nodes) :nodes(nodes){}
        vector<Node> &nodes;
    };
    struct populateNode{
        int last;
        populateNode(int i=0):last(i){}
        void operator()(Node &n){
            n.value=last++;
        }
    };
};

//template<class T>
class Bar{
public:
    virtual void fuck(Graph::Node *) =0;
};

void Graph::Node::fuck(Bar &boo){
    boo.fuck(this);
}

//template<class T>
void Graph::bfs(){
    queue<Node *> q;
    q.push(&nodes[0]);
    while(!q.empty()){
        Node *n = q.front();
        q.pop(); 
        n->colour=BLACK;
        cout << n-> value << endl;
        for(vector<Node *>::iterator i = n->adj.begin(); i != n->adj.end(); i++){
            if( (*i)->colour == WHITE ){
                q.push(*i);
            }
        }
    }
}


int main(){
    int n,x,y;
    cin >> n;
    vector<pair<int, int> > edges;
    while(cin >> x >> y){
        edges.push_back(make_pair(x,y));
    }
    Graph G(n, edges);
    G.bfs();
    return 0;
}
