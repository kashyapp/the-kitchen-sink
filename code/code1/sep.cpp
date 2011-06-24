#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

struct node{
    node * next;
    int value;
};

void sep(node *p, node **even, node **odd){
    node *e[2];
    node *o[2];
    e[0]=e[1]=o[0]=o[1]=NULL;

    node **t;
    
    while(p!=NULL){
        t = ((p->value) %2)? o : e;

        if(t[1]){
            t[1]->next = p;
            t[1] = p;
        }
        else{
            t[0] = t[1] = p;
        }
        p = p->next;
    }
    if(e[1]) e[1]->next=NULL;
    if(o[1]) o[1]->next=NULL;
    *even = e[0];
    *odd = o[0];
}

int main(){
    int i;
    node *h,*t;
    h=t=NULL;
    while(cin>>i){
        node *p = new node;
        p->value = i;
        p->next = NULL;
        if(t){
            t->next=p;
        }
        else{
            h=t=p;
        }
        t=p;
    }

    

    node *e,*o;
    sep(h,&e,&o);

    cout<<" sepped\n";

    t = e;
    while(t){
        cout<<t->value<<",";
        t=t->next;
    }
    cout<<endl;
    t = o;
    while(t){
        cout<<t->value<<",";
        t=t->next;
    }
    cout<<endl;

    return 0;
}

