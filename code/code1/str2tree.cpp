#include <iostream>
#include <stack>
using std::stack;
using std::ostream;
using std::endl;
using std::cout;

struct node{
    char value;
    node *sibling;
    node *child;
    node() :sibling(NULL),child(NULL){}
};


ostream& operator<<(ostream& o,const node* n){
    o << "[" << n->value;
    if (n->child != NULL){
        o << n->child;
    }
    o << "]";
    if(n->sibling != NULL){
        o << n->sibling;
    }
    return o;
}


int main(){
    char str[]="(1(2(5)(6))(3)(4(7)))";
    stack<node*> s;

    node *fakeroot = new node();
    fakeroot->value='*';
    fakeroot->sibling = NULL;
    fakeroot->child = NULL;
    s.push(fakeroot);

    for(char *i = &str[0]; *i != '\0'; i++){
        if(*i == '('){
        }
        else if(*i==')'){
            node *n = s.top();
            s.pop();
        }
        else{
            node *p = s.top();
            node *n = new node();
            n->value = *i;
            n->child = NULL;
            n->sibling = p->child;
            p->child = n;
            s.push(n);
        }
    }
    cout << fakeroot->child << endl;
    return 0;
}
