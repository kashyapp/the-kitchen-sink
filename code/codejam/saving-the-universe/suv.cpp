#include <iostream>
#include <cassert>
#include <map>
#include <string>
#include <cstring>

using namespace std;
#define L 101
#define S 100
#define Q 1000

int solve() {
    int switches = 0;
    char s[L];

    map<string, int> key;

    int n;
    cin >> n; cin.get(); // the newline

    for (int i = 0; i < n; i++) {
        cin.getline(s, L); 

        key[s] = i;
        //cout << s << " - " << key[s] << endl;
    }

    int q;
    cin >> q; cin.get(); // the newline

    bool zzz[S];
    memset(zzz, false, sizeof(zzz));
    int count = 0;

    int current = -1;

    for (int i = 0; i < q; i++) {
        cin.getline(s, L);

        //cout << s << " + " << key[s] << endl;

        int sk = key[s];

        //cout << current << " " << sk << endl;
        
        if (!zzz[sk]) {
            count++;
            if (count == n) {
                current = sk;
                switches++;
                memset(zzz, false, sizeof(zzz));
                count = 1;
            }

            zzz[sk] = true;
        }
    }

    return switches;
}

int main(int argc, char **argv) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
}
