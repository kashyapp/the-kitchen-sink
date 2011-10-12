#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    int val;
};

 void print(node *root, bool left) {
    if (root == NULL) return;
    
    bool hasLeft = (root->left) != NULL;
    bool hasRight = (root->right) != NULL;
    
    cout << root->val << " ";
    if (hasLeft ^ hasRight) {
        print(node->left, left);
        print(node->right, left);
    } else {
        if (left) {
            print(root->left, left);
        } else {
            print(root->right, left);
        }
    }
}

void printView(node *root){
/* For your reference
struct node {
	struct node *left,*right;
	int val;
};

typedef struct node node;
*/
    print(root, true);
    cout << endl;
    print(root, false);
    cout << endl;
}
