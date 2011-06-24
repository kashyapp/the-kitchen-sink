#include <iostream>
#include <vector>
using namespace std;
vector<int> mult(vector<int> &a){
    vector<int> b;
    int m = 1;
    for(int i = 0; i < a.size(); ++i){
        b.push_back(m);
        m *= a[i];
    }
    m = 1;
    for(int i = a.size()-1; i >=0; --i){
        b[i] *= m;
        m *= a[i];
    }
    return b;
}

int main(){
    vector<int> a;
    
    int i;
    while(cin >> i) a.push_back(i);
    
    vector<int> b = mult(a);

    for(int i=0; i < b.size(); ++i){
        cout << b[i] << ", ";
    }
    cout << endl;
    return 0;
}
