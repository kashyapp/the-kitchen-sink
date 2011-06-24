#include <iostream>
#include <string>
#include <deque>
#include <cstdio>
#include <cstring>
#include <stdint.h>

using namespace std;

class Node {
    Node *children[26];

    public:
    Node() {
        memset(children, 0, 26 * sizeof(Node*));
    }

    void add(char *s) {
        if (*s == '\0') { return; }

        int i = *s - 'a';
        if (children[i] == NULL) {
            children[i] = new Node();
        }
        children[i]->add(s+1);
    }

    bool accept(char c) {
        return NULL != children[c-'a'];
    }

    Node* to(char c) {
        return children[c-'a'];
    }
};

uint64_t counter = 0;

int trieverse(char *s, Node *currNode) {
    counter++;
    int count = 0;
    switch (*s) {
        case '\n':
        case '\0':
            count = 1;
            break;

        case '(': {
                      char *qstart = ++s;

                      while(*s != ')') ++s;
                      char *qend = s;

                      for (char *i = qstart; i != qend; ++i) {
                          char c = *i;
                          if (currNode->accept(c)) {
                              count += trieverse(s+1, currNode->to(c));
                          }
                      }
                  }
                  break;

        default:
                  char c = *s;
                  if (currNode->accept(c)) {
                      count += trieverse(s+1, currNode->to(c));
                  }
                  break;
    }

    return count;
}

int match(char *s, Node *tree) {
    return trieverse(s, tree);
}

int main() {
    char *line;
    size_t size = 0;

    unsigned int l, d, n;
    Node *tree = new Node();

    getline(&line, &size, stdin);
    sscanf(line, "%d %d %d", &l, &d, &n);

    while (d--) {
        int len = getline(&line, &size, stdin);
        if (line[len-1] == '\n') line[len-1] = '\0';
        tree->add(line);
    }

    int i = 0;
    while (n-- && ++i) {
        int len = getline(&line, &size, stdin);
        if (line[len-1] == '\n') line[len-1] = '\0';
        cout << "Case #" << i << ": " << match(line, tree) << endl;
    }
    cerr << counter << endl;
    return 0;
}
