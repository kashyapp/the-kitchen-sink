#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// searches for pattern in tree
// tree is a binary search tree
// pattern is again a tree
//
// Assumptions:
// binary search tree has duplicates
// with the property
// left <= root < right
Node *search(Node * tree, Node * pattern) {
    if (tree == NULL || pattern == NULL) {
	return NULL;
    }
    if (pattern->data == tree->data && match(tree, pattern)) {
	return tree;
    }
    if (pattern->data > tree->data) {
	return search(tree->right, pattern);
    }
    return search(tree->left, pattern);
}

int match(Node * tree, Node * pattern) {
    if (pattern == NULL) {
	return TRUE;
    }
    if (tree == NULL) {
	return FALSE;
    }
    return (tree->data == pattern->data 
        && match(tree->left, pattern->left)
	&& match(tree->right, pattern->right));
}

Node* constructFromPre(int * start, int *end) {
     
}


// NOTES:
// this search looks if there exists a matching substructure in the tree, and 
// not for a proper subtree
//
// to do a proper subtree search, an easy way is to do a preorder traversal of 
// both the tree and the pattern and then do a string matching.
