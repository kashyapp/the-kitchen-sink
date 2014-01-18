#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

void boo(queue<pair<short, short> > &q, queue<int> &hops, int i, int j, int m, int n, int hop) {
    if (i >= 0 && i < m
        && j >=0 && j < n) {
            q.push(make_pair(i,j));
            hops.push(hop);
        }
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector< vector<short> > cells(m, vector<short>(n));
    
    for (int i = 0; i < m; ++i ) {
        for (int j = 0; j < n; ++j) {
            cin >> cells[i][j];
        }
    }
    
    short ux, uy;
    short hx, hy;
    cin >> ux >> uy >> hx >> hy;

    pair<short, short> target = make_pair(hx, hy);
    
    queue< pair<short, short> > q;
    queue<int> hops;
    
    q.push(make_pair(ux, uy));
    hops.push(0);
    
    while (!q.empty()) {
        pair<short, short> here = q.front(); q.pop();
        int hop = hops.front(); hops.pop();
        
        if (here == target) {
            cout << hop << endl;
            return 0;
        }
        
        short distance = cells[here.first][here.second];
        if (distance > 0) {
            cells[here.first][here.second] = 0;
            
            for(int i = 0; i <= distance; ++i) {
                int j = distance - i;
                boo(q, hops, here.first + i, here.second + j, m, n, hop+1);
                boo(q, hops, here.first - i, here.second + j, m, n, hop+1);
                boo(q, hops, here.first + i, here.second - j, m, n, hop+1);
                boo(q, hops, here.first - i, here.second - j, m, n, hop+1);
            }
        }
    }
    
    cout << "LET HER GO" << endl;
    
    return 0;
}
