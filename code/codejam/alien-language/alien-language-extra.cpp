#include <iostream>
#include <string>
#include <deque>
#include <cstdio>
#include <cstring>
#include <stdint.h>

using namespace std;

#define L 20

uint64_t djb2(unsigned char* str) {
    uint64_t hash = 5381;
    unsigned char c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

class Foo {
    public:
    virtual void end() =0;
    virtual bool accept(char c) =0;
};

class Collect : public Foo {
    char buf[L+1];

    public:
    virtual void end() {
    }

    virtual bool accept(char c) {
        return false;
    }
};

class Node {
    Node *children[26];

    public:
    Node() {
        memset(children, 0, 26 * sizeof(Node*));
    }

    void add(char *s) {
        if (*s == '\0') {
            //cerr << "added " << endl;
            return;
        }
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

int trieverse(char *s, Node *currNode) {
    int count = 0;
    switch (*s) {
        case '\n':
        case '\0':
            count = 1;
            //cerr << "accepted" << endl;
            break;

        case '(': {
                      char *qstart = ++s;

                      while(*s != ')') ++s;
                      char *qend = s;

                      for (char *i = qstart; i != qend; ++i) {
                          char c = *i;
                          if (currNode->accept(c)) {
                              count += trieverse(s+1, currNode->to(c));
                          } else {
                              //cerr << "Aborting from here : " << c << endl;
                          }
                      }
                  }
                  break;

        default:
                  char c = *s;
                  if (currNode->accept(c)) {
                      count += trieverse(s+1, currNode->to(c));
                  } else {
                      //cerr << "Aborting from here : " << c << endl;
                  }
                  break;
    }

    return count;
}

void generate(char *s, char *buf, int p) {
    switch (*s) {
        case '\n':
        case '\0':
            buf[p] = '\0';
            //cerr << buf << endl;
            break;

        case '(': {
                char *qstart = ++s;

                while(*s != ')') ++s;
                char *qend = s;

                for (char *i = qstart; i != qend; ++i) {
                    buf[p] = *i;
                    generate(s+1, buf, p+1);
                }
            }
            break;
        
        default:
            buf[p] = *s;
            generate(s+1, buf, p+1);
            break;
    }
}

int match(char *s) {
    char buf[L+1];
    generate(s, buf, 0);

    return 3; // TODO
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
    return 0;
}
