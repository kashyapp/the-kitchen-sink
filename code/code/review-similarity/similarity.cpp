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

template<class P>
void iterate_words(P p) {
    char *s = NULL;
    size_t tmp;
    getline(&s, &tmp, stdin);
     
    int total = 0;
    bool in_a_word = false;

    for (; *s != '\0'; s++) {
        char c = *s;
        switch(c) {
            case ' ':
            case ',':
            case '.':
            case '\n':
                if (in_a_word) {
                    p.word();

                    total++;
                    in_a_word = false;
                }

                break;
            default:
                in_a_word = true;
                p.chr(tolower(c));
        }
    }

    p.finish(total);
}

struct WordMatcher {
    Trie *trie;
    int match;
    bool matched;

    WordMatcher(Trie *_trie) {
        match = 0;
        matched = false;
        trie = _trie;
    }

    void word() {
        if (trie->isgood())
            matched = true;

        if (matched) {
            match++;
        }

        trie->reset();
        matched = false;
    }

    void chr(char c) {
        trie->enter(c);
        if (trie->isword())
            matched = true;
    }

    void finish(int total) {
        cerr << total << " " << match << endl;
        cout << round(100.0 * match / total) << endl;
    }
};

struct TrieBuilder {
    Trie *trie;
    TrieBuilder(Trie *_trie) {
        trie = _trie;
    }
    void word() {
        trie->finish();
    }
    void chr(char c) {
        trie->add(c);
    }
    void finish(int total) {
        trie->reset();
    }
};

int main() {
    Trie trie;
    iterate_words(TrieBuilder(&trie));
    iterate_words(WordMatcher(&trie));

    return 0;
}
