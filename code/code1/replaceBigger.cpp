#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>
using namespace std;

// in:  5  8  7  4  5  9  3 12
// out: 8  9  9  5  9 12 12 -1 

void replaceBigger(vector<int> &v) {
    stack<int> s;
    for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
        int replace = -1;
        int curr = *i;
        while (!s.empty()) {
            if (s.top() > curr) {
                replace = s.top();
                break;
            }
            s.pop();
        }
        s.push(curr);
        *i = replace;
    }
}

int main() {
    vector<int> v;
    int i;
    while (cin >> i) {
        v.push_back(i);
    }
    replaceBigger(v);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}


