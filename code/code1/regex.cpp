#include <string>
#include <iostream>
#include <utility>


using namespace std;

bool regexmatcher(const char *s, const char *pattern) {
    if (*pattern == '\0') {
        return (*s == '\0');
    }

    char next = *pattern;
    pattern++;

    bool glob = false;

    if (*pattern == '*') {
        glob = true;
        pattern++;
    }

    if (glob) {
        do {
            if (regexmatcher(s, pattern)) {
                return true;
            }
            s++;
        } while (*s != '\0' && next == '.' || *s == next);
        return regexmatcher(s, pattern);
    } else {
        if (*s != '\0' && next == '.' || *s == next) {
            return regexmatcher(s+1, pattern);
        } else {
            return false;
        }
    }

    return false;
}

bool rematch(const char *s, const char *pattern) {
    if (*pattern == '\0') {
        return (*s == '\0');
    }

    char next = *pattern;
    bool glob = (*(pattern + 1) == '*');

    if (glob) {
        return 
            rematch(s, pattern + 2) || 
            (*s != '\0' && '.' == next || *s == next) && rematch(s+1, pattern);
    } else {
        if (*s != '\0' && '.' == next || *s == next) {
            return rematch(s+1, pattern + 1);
        }
    }
    return false;
}

int main() {
    string pat;
    string str;
    while (cin >> str >> pat) {
        cout 
            << regexmatcher(str.c_str(), pat.c_str()) << " "
            << rematch     (str.c_str(), pat.c_str()) << " "
            << endl;
    }
    return 0;
}
