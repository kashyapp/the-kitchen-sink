#include "iostream"
#include <cassert>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;

void genparen_(char *orig, char *s, int open, int close) {
    assert(open <= close);
    if (close == 0) {
        cout << orig << endl;
    } else {
        if (open > 0) {
            *s = '(';
            genparen_(orig, s+1, open-1, close);
        }
        if (open < close) {
            *s = ')';
            genparen_(orig, s+1, open, close-1);
        }
    }
}

void genparen2(char *buffer, int nextPosition, int open, int close) {
    assert(open <= close);
    if (close == 0) {
        cout << buffer << endl;
    } else {
        if (open < close) {
            buffer[nextPosition] = ')';
            genparen2(buffer, nextPosition + 1, open, close-1);
        }
        if (open > 0) {
            buffer[nextPosition] = '(';
            genparen2(buffer, nextPosition + 1, open-1, close);
        }
    }
}

void genparen(int n) {
    char *s = new char[1 + 2*n];
    s[2*n] = '\0';
    genparen_(s, s, n, n);
    cout << endl;
    genparen2(s, 0, n, n);
}

int main(int argc, char **argv) {
    assert(argc == 2 && "Needs an integer argument");

    int n = atoi(argv[1]);
    
    genparen(n);

    return 0;
}
