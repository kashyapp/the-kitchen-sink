#include <iostream>
#include <stack>
using namespace std;

int data[200000];
int sums[200000];
int last = 0;
int summ = 0;

void add(int t) {
    last++;
    data[last] = t;
    sums[last] = summ = summ + t;
    cerr << summ << endl;
}

void sum() {
        int start, end;
        cin >> start >> end;
        start = last - start + 1;
        end = last - end;
        cout << sums[start] - sums[end] << endl;
}

int main() {
    int n;
    cin >> n;
        stack<int> stk;
    for (int i = 0; i < n; ++i) {
                int t;
                cin >> t;
                stk.push(t);
    }
        for (int i = 0; i < n; ++i) {
                add(stk.top());
                stk.pop();
        }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        switch (c) {
            case 'G':
                sum();
                                break;
            case 'A':
                                int t;
                                cin >> t;
                add(t);
                                break;
        }
    }
        return 0;
}
