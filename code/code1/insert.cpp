#include <deque>
#include <iostream>
using namespace std;

struct node{
	node *left;
	node *right;
	int v;
};

void inorder(node *n){
	if(n){
	inorder(n->left);
	cout<<n->v<<" ";
	inorder(n->right);
	}
}

void preorder(node *n){
	if(n){
	cout<<n->v<<" ";
	preorder(n->left);
	preorder(n->right);
	}
}

void postorder(node *n){
	if(n){
	postorder(n->left);
	postorder(n->right);
	cout<<n->v<<" ";
	}
}

void insert(node **n, int i){
	node *p=*n;
	if(*n==NULL){
		*n = new node();
		(*n)->v = i;
	}
	else if(i>p->v){
		insert(&p->right,i);
	}
	else{
		insert(&p->left,i);
	}
}

void level(node *n){
	if(n==NULL) return;
	deque<node *> q;
	int w,wt;
	q.push_back(n);
	w=1;
	while(!q.empty()){
		node *p = q.front();
		q.pop_front();
		cout << p->v <<" ";
		if(p->left!=NULL) {q.push_back(p->left); wt++;}
		if(p->right!=NULL) {q.push_back(p->right); wt++;}
		if(!--w) {w=wt;wt=0;cout<<endl;}
	}
}

void level_alt(node *n){
	if(n==NULL) return;
	deque<node *> q,qo;
	q.push_back(n);
	bool lr = true;
	node *p;
	while(!q.empty()){
		p = q.front();
		q.pop_front();
		cout << p->v << " ";

		if(lr){//l->r
			if(p->left!=NULL) qo.push_front(p->left);
			if(p->right!=NULL) qo.push_front(p->right);
		}
		else{//r->l
			if(p->right!=NULL) qo.push_front(p->right);
			if(p->left!=NULL) qo.push_front(p->left);
		}
		if(q.empty()){
			q.swap(qo);
			lr = !lr;
			cout << endl;
		}
	}
}

ostream& operator<<(ostream &o, node* n){
	if(n!=NULL){
		o << (unsigned int)n << "," << n->v << "," << (unsigned int)n->left << "," << (unsigned int)n->right << endl;
		o << n->left;
		o << n->right;
	}
	return o;
}

int main(){
	node *root=NULL;
	int i;
	while(cin>>i){
		insert(&root, i);
	}
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	level(root);
	cout<<endl;
	level_alt(root);
	cout<<endl;
	cout<<root;
	return 0;
}
