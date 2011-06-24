#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dupe(vector<int> &v){
    int l = v.size();
    int n = l-2; //numbers between [1,n]
    for(int i=1;i<=n;++i){
        if(v[i]!=i){
            while(true){
                if(i==v[i])
                    break;
                else if(v[i]==v[v[i]])
                    return v[i];
                else
                    swap(v[i],v[v[i]]);
            }
        }
    }
    return v[0];
}

int main(){
    int i;
    vector<int> v;
    while(cin>>i)
        v.push_back(i);
    cout << dupe(v) <<endl;
    return 0;
}
