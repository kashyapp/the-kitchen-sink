#include <iostream>
#include <climits>
using namespace std;

#define _N_ new Node

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int _v, Node *_l, Node *_r) 
        :value(_v), left(_l), right(_r) {}
    Node(int _v) 
        :value(_v), left(NULL), right(NULL) {}
};

int treeMax(Node *root) {
    int max = INT_MIN;
    if (root != NULL) {
        max = root->value; 
        if (root->left) {
            int left = treeMax(root->left);
            max = left > max ? left : max;
        }
        if (root->right) {
            int right = treeMax(root->right);
            max = right > max ? right : max;
        }
    }
    return max;
}

Node* constructTree() {
    Node *root = 
        _N_(10, _N_(11, _N_(3, _N_(23), NULL), NULL), _N_(12, _N_(14), _N_(5, NULL, _N_(4, _N_(16), _N_(19)))));
    return root;
}

int main() {
    Node *root = constructTree();
    cout << treeMax(root) << endl;
    return 0;
}

