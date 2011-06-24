#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){
    int i;
    int k;
    vector<int> v;
    cin >> k;
    while(cin >> i) v.push_back(i);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}
