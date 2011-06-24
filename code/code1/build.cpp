#include <iostream>
#include <list>
using namespace std;
struct node{
    char value;
    list<node*> children;
};

ostream& operator<<(ostream &oss,node* n){
    oss << "[" << n->value;
    for(list<node*>::iterator i=n->children.begin();i!=n->children.end();++i){
        oss << *i;
    }
    oss << "]";
    return oss;
}

node * build(char **s){
    char *c = *s;
    node *n = new node();
    n->value = *++c;
    while(*++c!=')'){
        n->children.push_back(build(s));
    }
    return n;
}

int main(){
    char *s="(3(5(6)(7(k(u)(n)(t)(a)(l))))(8)(0))";
    node *root = build(&s);
    cout << root << endl;
    return 0;
}
