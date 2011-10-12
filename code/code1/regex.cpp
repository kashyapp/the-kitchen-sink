#include <string>
#include <iostream>
#include <utility>
#include <cassert>
#include <map>
#include <cstring>

using namespace std;

#define IS_NULL(s) (s == '\0')
#define IS_NOT_NULL(s) (s != '\0')
#define assertnot(s) assert(!(s))

class RegexMatcher {
    protected:
    inline bool charMatches(char stringChar, char patternChar) {
        return stringChar != '\0' && (patternChar == '.' || stringChar == patternChar);
    }

    public:
    virtual bool operator()(const char *str, const char *pattern) =0;
};


class Hybrid : public RegexMatcher {
public:
    bool operator()(const char *str, const char *pattern) {
        char currentStringChar = *str;
        char currentPatternChar = *pattern;

        if (IS_NULL(currentPatternChar)) {
            return IS_NULL(currentStringChar);
        }

        pattern++;

        bool star = false;

        if (*pattern == '*') {
            star = true;
            pattern++;
        }

        if (star) {
            do {

                if ((*this)(str, pattern)) {
                    return true;
                }
                currentStringChar = *(++str);

            } while (charMatches(currentStringChar, currentPatternChar));

            return (*this)(str, pattern);

        } else {
            if (charMatches(currentStringChar, currentPatternChar)) {
                return (*this)(str + 1, pattern);
            } else {
                return false;
            }
        }

        return false;
    }
};

class CachingMatcher : public RegexMatcher {
    const char *str_;
    const char *pat_;

    short *cache;
    int width, height;

    RegexMatcher *matcher_;

    public:
    CachingMatcher (const char *str, const char *pat, RegexMatcher *matcher) : 
        str_(str), pat_(pat),
        width(strlen(str)), height(strlen(pat)),
        matcher_(matcher)
    {
        int size = height * width;

        cache = new short[size];
        memset(cache, 0, size * sizeof(short));
    }

    ~CachingMatcher () {
        delete[] cache;
    }

    bool operator()(const char *str, const char *pat) {
        int w = str - str_;
        int h = pat - pat_;

        int index = h * width + w;
        short cached = cache[index];

        if (cached) {
            cerr << "cache hit" << endl;
            return cached - 1;
        } else {
            cerr << "cache miss" << endl;
            bool match = (*matcher_)(str, pat);
            cache[index] = 1 + match;
            return match;
        }
    }
};

class PureRecursive : public RegexMatcher {
public:
    bool operator()(const char *str, const char *pattern) {
        //cerr << str << " " << pattern << endl;
        char currentStringChar = *str;
        char currentPatternChar = *pattern;

        if (IS_NULL(currentPatternChar)) {
            return IS_NULL(currentStringChar);
        }

        bool star = (*(pattern + 1) == '*');

        if (star) {
            return (*this)(str, pattern + 2) 
                || ( charMatches(currentStringChar, currentPatternChar) && (*this)(str+1, pattern) );
        } else {
            if (charMatches(currentStringChar, currentPatternChar)) {
                return (*this)(str+1, pattern + 1);
            }
        }
        return false;
    }

};

void test(bool (*matcher)(const char *, const char *)) {
    assert(matcher("a", "a"));
    assert(matcher("a", "."));
    assert(matcher("a", ".*a"));
    assert(matcher("a", "b*a"));
    assert(matcher("a", "ab*"));
    assert(matcher("a", "a.*"));
    assert(matcher("a", ".*a.*"));
    assert(matcher("ab", "a*b*.*a*b*"));
    assert(matcher("abcde", "abcde*"));
    assertnot(matcher("ab", "a*"));
    assertnot(matcher("aaaaaaaaaaaa","a*a*a*a*a*a*a*a*a*a*a*a*b"));
    //assert(matcher("ababababababababababababababaabababab", "a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*a*b*a*b*a*b*a*b*"));
}

int main() {
    string pat;
    string str;

    //test(regexmatches);
    //test(rematch);
    
    PureRecursive rematch;
    Hybrid regexmatches;

    while (cin >> str >> pat) {
        CachingMatcher cache(str.c_str(), pat.c_str(), &rematch);
        cout 
            << regexmatches(str.c_str(), pat.c_str()) << " "
            << rematch     (str.c_str(), pat.c_str()) << " "
            << cache       (str.c_str(), pat.c_str()) << " "
            << endl;
    }
    return 0;
}
