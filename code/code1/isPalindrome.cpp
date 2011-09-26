#include <iostream>
#include <cassert>

using namespace std;

template<class T>
struct Node {
    T value;
    Node<T> *next;

    Node(T _value) : value(_value), next(NULL) {}
};

template<class T>
ostream& operator<<(ostream& os, const Node<T> &node) {
    os << "(" << (void*) &node << ") " << node.value << ", ";
    if (node.next) {
        return os << *(node.next);
    }
    return os;
}


template<class T>
Node<T>* isPalindrome(Node<T> *p, Node<T> *q) {
    if (q == NULL) {
        //cerr << "reached midway, even length" << endl;
        return p;
    }

    if (q->next == NULL) {
        //cerr << "reached midway, odd length" << endl;
        return p->next;
    }

    //cout << p->value << " " << q->value << endl;

    Node<T> *ret = isPalindrome(p->next, q->next->next);

    if (ret == NULL) {
        cerr << "already got a mismatch, throwing up" << endl;
        return NULL;
    }

    if (ret->value == p->value) {
        cerr << "found a match ["<< p->value << " == " << ret->value << "]" << endl;
        if (ret->next != NULL) {
            return ret->next;
        } else {
            cerr << "success, return the full list" << endl;
            return p;
        }
    } else {
        cerr << "found a mismatch ["<< p->value << " != " << ret->value << "] throwing up" << endl;
        return NULL;
    }
}

typedef Node<char> MyNode;

int main(int argc, char **argv) {
    assert(argc == 2 && "Missing argument");

    MyNode *list = NULL;
    MyNode **head = &list;

    char *s = argv[1];
    while (*s != '\0') {
        MyNode *node = new MyNode(*s);
        *head = node;
        head = &(node->next);
        s++;
    }

    //cout << *list << endl; 

    cout << isPalindrome(list, list) << endl;

    return 0;
}
