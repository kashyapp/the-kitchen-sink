#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main(){
    vector<int> v;
    int i;
    while(cin>>i)
        v.push_back(i);
    int n=v.size();
    for(int x=0;x<n;){
        if(v[x] == x || v[x] == -1){
            x++;
        }
        else if(v[x] == n){
            v[x] = -1;
            x++;
        }
        else{
            swap(v[x],v[v[x]]);
        }
    }
    copy(v.begin(),v.end(),ostream_iterator<int>(cout,", "));
    cout << endl;

    return 0;
}
