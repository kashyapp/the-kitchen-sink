#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define I(c) ((c) - 'A')

unsigned int O[26];
int  C[26][26];

int stackcount[26];
unsigned int stackset;
int top = -1;
int stack[100];

void reset() {
    memset(O, 0, sizeof(O));
    memset(C, -1, sizeof(C));

    memset(stackcount, 0, sizeof(stackcount));
    stackset = 0;
    top = -1;
}

void drain() {
    memset(stackcount, 0, sizeof(stackcount));
    stackset = 0;
    top = -1;
}

void push(int c) {
    if (! stackcount[c]++) {
        unsigned int s = 1 << c;
        stackset |= s;
    }

    stack[++top] = c;
}

void replace(int c) {
    int t = stack[top];
    stack[top] = c;

    if (! --stackcount[t]) {
        unsigned int s = ~(1 << t);
        stackset &= s;
    }

    if (! stackcount[c]++) {
        unsigned int s = 1 << c;
        stackset |= s;
    }

}

int combine(int c) {
    int t = stack[top];
    return C[t][c];
}

bool opposite(int c) {
    return stackset & O[c];
}

void solve() {
    int c, d, n;

    reset();

    cin >> c;
    char comb[4];
    while (c--) {
        cin >> comb;    
        int x = I(comb[0]);
        int y = I(comb[1]);
        int z = I(comb[2]);

        C[x][y] = C[y][x] = z;
    }
 
    cin >> d;
    char opp[3];
    while (d--) {
        cin >> opp;
        int x = I(opp[0]);
        int y = I(opp[1]);

        unsigned int xs = 1 << x;
        unsigned int ys = 1 << y;

        O[x] |= ys;
        O[y] |= xs;
    }

    char ele[101];
    cin >> n >> ele;

    for (int i = 0; i < n; ++i) {
        int c = I(ele[i]);
        int combined;
        if (top >= 0 && (combined = combine(c)) >= 0) {
            replace(combined);
        } else if(opposite(c)) {
            drain();
        } else {
            push(c);
        }
    }

    cout << "[";
    if (top >= 0) {
        cout << (char)('A' + stack[0]);
    }
    for(int i = 1; i <= top; ++i) {
        cout << ", " << (char)('A' + stack[i]);
    }
    cout << "]";
}

int main() {
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
