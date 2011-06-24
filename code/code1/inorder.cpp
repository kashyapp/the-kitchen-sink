#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <assert.h>

template<typename T>
struct Node{
    Node * left;
    Node * right;
    T value;
    bool done;
};

template <typename T>
std::ostream& operator << (std::ostream& o, Node<T> *p){
    o << " - " << p->value << " - ";
    return o;
}

template <typename T>
std::ostream& operator << (std::ostream& o, Node<T> &p){
    o << " : " << p.value << " : ";
    return o;
}

template<typename T>
void r_inorder(Node<T> *p){
    if(p==NULL)
        return;
    if(p->left != NULL)
        r_inorder(p->left);
    std::cout << *p << std::endl;
    if(p->right != NULL)
        r_inorder(p->right);
}
/*
template<typename T>
void i_inorder(Node<T> *p){
    std::vector< Node<T>* > s;
    int pucount = 0, pocount = 0;

    do{
        while(p){
            s.push_back(p);
            p=p->left;
        }
        p=s.back();
        s.pop_back();
        std::cout << *p << std::endl;
        p = p->right; 
    }while(!s.empty()||p);
}
*/
/*
*/
template<typename T>
void i_inorder(Node<T> *p){
    std::vector< Node<T>* > s;
    int pucount = 0, pocount = 0;

    while(!s.empty() || p){
        if(p){
            s.push_back(p);
            p = p->left;
        }
        else{
            p = s.back(); s.pop_back();
            std::cout << *p << std::endl;
            p = p->right;
        }
    }
}


template<typename T>
void i_preorder(Node<T> *p){
    std::vector< Node<T>* > s;
    assert(p!=NULL);
    s.push_back(p);
    while(!s.empty()){
        p = s.back(); s.pop_back();
        std::cout << *p << std::endl;
        if(p->right)
            s.push_back(p->right);
        if(p->left)
            s.push_back(p->left);
    }
}

template<typename T>
void i_postorder(Node<T> *p){
    std::vector< Node<T>* > s;
    assert(p!=NULL);
    p->done=false;
    s.push_back(p);
    while(!s.empty()){
        p = s.back();
        if(p->done){
            s.pop_back();
            std::cout << *p << std::endl;
        }
        else{
            p->done=true;
            if(p->right){
                p->right->done = false;
                s.push_back(p->right);
            }
            if(p->left){
                p->left->done = false;
                s.push_back(p->left);
            }
        }
    }
}

template<typename T>
void i2_postorder(Node<T> *p){
    std::vector< Node<T>* > s;
    std::vector< Node<T>* > s2;
    assert(p!=NULL);
    s.push_back(p);
    s2.push_back(p);
    while(!s.empty()){
        p = s.back();
        if(!s2.empty() && s2.back() == p){
            s2.pop_back();
            if(p->right){
                s.push_back(p->right);
                s2.push_back(p->right);
            }
            if(p->left){
                s.push_back(p->left);
                s2.push_back(p->left);
            }
        }
        else{
            s.pop_back();
            std::cout << *p << std::endl;
        }
    }
}

template <class T>
void level_order(Node<T> *p){
	std::deque< Node<T> * > q;
	q.push_back(p);
	q.push_back(NULL);
	while(!q.empty()){
		Node<T> *p = q.front();
		q.pop_front();
		if(p==NULL){
			if(!q.empty()) q.push_back(NULL);
			std::cout << std::endl;
		}
		else{
			std::cout << *p ;
			if(p->left)
				q.push_back(p->left);
			if(p->right)
				q.push_back(p->right);
		}
	}
}

template <class T>
void level_order_alt(Node<T> *p){
	typedef std::deque< Node<T> * > q_t;
	q_t q, qo;

	q.push_back(p);
	while(!q.empty()){
		p = q.front();
		q.pop_front();
		if(p->left)
			q.push_back(p->left);
		if(p->right)
			q.push_back(p->right);
		std::cout << *p << std::endl;
		if(q.empty())
			q.swap(qo);
	}
}

int main(){
    Node<int> tree[9];
    tree[0].value=4; tree[0].left = &tree[1]; tree[0].right = &tree[4];
    tree[1].value=2; tree[1].left = &tree[2]; tree[1].right = &tree[3];
    tree[4].value=5; tree[4].left = NULL;     tree[4].right = &tree[5];
    tree[2].value=1; tree[2].left = NULL;     tree[2].right = NULL;     
    tree[3].value=3; tree[3].left = NULL;     tree[3].right = NULL;     
    tree[5].value=7; tree[5].left = &tree[6]; tree[5].right = &tree[7];     
    tree[6].value=6; tree[6].left = NULL;     tree[6].right = NULL;     
    tree[7].value=9; tree[7].left = &tree[8]; tree[7].right = NULL;     
    tree[8].value=8; tree[8].left = NULL;     tree[8].right = NULL;     

    r_inorder(&tree[0]);
/**
    s_inorder(&tree[0]);
 */
    i_inorder(&tree[0]);
    //i_preorder(&tree[0]);
    //i_postorder(&tree[0]);
    //i2_postorder(&tree[0]);
	//level_order(&tree[0]);
//level_order_alt(&tree[0]);
    return 0;
}
