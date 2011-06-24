#include <iostream>
#include <cstdlib>

using namespace std;

#define NOT(c) (1 - (c))

int get(char c) {
    switch (c) {
        case 'O':
            return 0;
        case 'B':
            return 1;
    }
}

int solve() {
    int n;
    cin >> n;
    int timer = 0;

    int t[2] = {0, 0};
    int p[2] = {1, 1};
   
    while (n--) {
        char c;
        int button;

        cin >> c >> button;
        int who = get(c);

        int delta = abs(button - p[who]);
        p[who] = button;

        if (t[who]) {
            if (t[who] >= delta) {
                delta = 0;
            } else {
                delta -= t[who];
            }
        }

        t[who] = 0;
        t[NOT(who)] += (1 + delta); 
        timer += (1 + delta);
    }

    return timer;
}

int main() {
    int nTest;
    cin >> nTest;
    
    for (int i = 1; i <= nTest; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}
