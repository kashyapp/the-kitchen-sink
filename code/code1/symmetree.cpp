#include <iostream>
#include <vector>

using namespace std;

struct node {
    node *left;
    node *right;

    node(node *left_, node *right_) : left(left_), right(right_) {}
};

node* t(node *left, node *right) {
    return new node(left, right); 
}

node* t() {
    return t(NULL, NULL);
}

void print(node *tree, int shift) {
    if (tree != NULL) {
        for (int i = 0; i < shift; i++) {
            cout << "   ";
        }
        cout << "x" << endl;
        print(tree->left, shift + 1);
        print(tree->right, shift + 1);
    } else {
        for (int i = 0; i < shift; i++) {
            cout << "   ";
        }
        cout << "NULL" << endl;
    }
}

bool symmetree(node *tree) {
    return true;
}

int main() {
    node *tree = t(
            t(
                NULL, 
                t(
                    t(),
                    t(NULL, t())
                    )
                ),
            t(
                t(
                    t(t(), NULL),
                    t()
                    ), 
                NULL
                )
            );
    print(tree, 0);
    cout << symmetree(tree) << endl;
    return 0;
}
