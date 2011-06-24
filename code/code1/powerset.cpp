#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void print(const char *s) {
    cout << '{';
    if (*s != '\0') {
        cout << *s;
    }
    while (*(++s) != '\0') {
        cout << ',' << *s;
    }
    cout << '}' << endl;
}

void powerset_(const char *s, char *d, int i) {
    if (*s == '\0') {
        d[i] = '\0';
        print(d);
    } else {
        powerset_(s+1, d, i);
        d[i] = *s;
        powerset_(s+1, d, i+1);
    }
}

void powerset(string &s) {
    char *d = new char[1 + s.size()];
    powerset_(s.c_str(), d, 0);
}

int main() {
    string s;
    while (cin >> s) {
        powerset(s);
    }
    return 0;
}
