#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct node {
    node* children[26];
    bool word;
    node() : word(false) {
        memset(children, 0, 26 * sizeof(node*));
    }
};

struct Trie {
    node *root,
         *current;

    Trie() {
        root = current = new node();
    }

    void reset() {
        current = root;
    }

    void finish() {
        if (current != root) current->word = true;
        reset();
    }

    bool isgood() const {
        return current != NULL;
    }

    bool isword() const {
        return isgood() && current->word;
    }

    void enter(char c) {
        int i = c - 'a';
        
        if (isgood()) {
            current = current->children[i];
        }
    }

    void add(char c) {
        int i = c - 'a';
        if (current->children[i] == NULL) {
            current->children[i] = new node();
        }
        enter(c);
    }
};

int main() {
    char *s1 = NULL;
    char *s2 = NULL;

    size_t t;
    size_t l1 = getline(&s1, &t, stdin);
    size_t l2 = getline(&s2, &t, stdin);
     
    Trie trie;

    for (; *s1 != '\0'; s1++) {
        char c = *s1;
        switch(c) {
            case ' ':
            case ',':
            case '.':
            case '\n':
                trie.finish();
                break;
            default:
                trie.add(tolower(c));
        }
    }
    trie.reset();

    int total = 0;
    int match = 0;

    bool matched = false;
    bool in_a_word = false;

    for (; *s2 != '\0'; s2++) {
        char c = *s2;
        switch(c) {
            case ' ':
            case ',':
            case '.':
            case '\n':
                if (in_a_word) {
                    total++;

                    if (trie.isgood())
                        matched = true;

                    if (matched) {
                        match++;
                    }

                    trie.reset();
                    matched = false;
                    in_a_word = false;
                }

                break;
            default:
                in_a_word = true;
                trie.enter(tolower(c));
                if (trie.isword())
                    matched = true;
        }
    }

    cerr << total << " " << match << endl;
    cout << round(100.0 * match / total) << endl;

    return 0;
}
