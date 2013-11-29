#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    
    vector<int> rating(n);
    vector<int> hike(n, x);
    
    for (int i=0; i<n; ++i) {
        cin >> rating[i];
    }
        
    cerr << hike[0] << " ";
    for (int i=0; i<n-1; ++i) {
        if (rating[i+1] > rating[i]) {
            hike[i+1] = hike[i] + x;
        } else if (rating[i+1] == rating[i]) {
            hike[i+1] = hike[i];
        }
        cerr << hike[i+1] << " ";
    }
    cerr << endl;
    
    for (int i=n-1; i>0; --i) {
        if (rating[i-1] > rating[i]) {
            hike[i-1] = max(hike[i-1], hike[i] + x);
        } else if (rating[i-1] == rating[i]) {
            hike[i-1] = hike[i];
        }
    }
    
    int total = 0;
    for (int i=0; i<n; ++i) {
        total += hike[i];
        cerr << hike[i] << " ";
    }
    cerr << endl;
    
    cout << total << endl;
    
    return 0;
}
