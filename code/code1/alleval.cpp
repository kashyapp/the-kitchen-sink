#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;

void join(set<int> *result, char oper, const set<int> &left, const set<int> &right) {
    int mult = (oper == '-') ? -1 : 1; //mult "-1" takes care of subtraction

    for(set<int>::iterator li = left.begin(); li != left.end(); li++) {
        for(set<int>::iterator ri = right.begin(); ri != right.end(); ri++) {
            result->insert(*li + mult * *ri); 
        }
    }
}

set<int> allval(const char* start, const char* end) {
    set<int> result;
    bool hasOper = false;
    for (const char *i = start; i != end; i++) {
        switch(*i) {
            case '-':
            case '+':
                hasOper = true;
                set<int> left = allval(start, i);
                set<int> right = allval(i+1, end);
                join(&result, *i, left, right);
        }
    }
    if (!hasOper) {
        int n = atoi(start);
        result.insert(n);
    }
    return result;
}

int main() {
    char* exprstr;
    size_t len;
    while (getline(&exprstr, &len, stdin) > 0) {
        set<int> result = allval(exprstr, exprstr + strlen(exprstr));
        copy(result.begin(), result.end(), ostream_iterator<const int>(cerr, " "));
        cerr << endl;
        cout << result.size() << endl;
    }
    return 0;
}
