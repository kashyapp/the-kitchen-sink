#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

void permute(const char*, char*);

int main() {
    string s;
    cin >> s;
    char *str = new char[s.size()+1];
    strcpy(str, s.c_str());
    permute(str, str);
    return 0;
}

//permutations with unique characters
void permute(const char *s, char *p) {
    if (*p == '\0') {
        cout << s << endl;
    }
    for (char *t = p; *t != '\0'; ++t) {
        swap(*t, *p);
        permute(s, p+1);
        swap(*t, *p);
    }
}
