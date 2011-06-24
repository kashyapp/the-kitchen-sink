#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main(){
    int m,n,k;
    while(cin >> m >> n >> k){
    int l = m+n;
    int count = 0;
    vector<bool> circle;

    assert(k<=m+1 || !"too few boys to step over");

    for(int i=0; i<l; ++i)
        circle.push_back(true);

    for(int i=0,j=k; n>0; i=(i+1)%l,count++){
        if(circle[i])
            j--;
        if(j==0){
            circle[i]=false;
            j = k;
            n--;
        }
    }


    for(int i=0; i<l; ++i)
        cout << circle[i] << " ";
    cout << endl;
    cout << "terminated after " << count << " steps" << endl;
    }
    return 0;
}
