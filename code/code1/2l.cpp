#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;



int main(){
    int l1=0, l2=1;
    vector<int> v;

    int k;
    while (cin >> k)
        v.push_back(k);

    if(v[l2]>v[l1])
        swap(l1,l2);

    for(int i=2; i < v.size(); i++){
        if(v[i]>v[l2])
            l2=i;
        
        if(v[l2]>v[l1])
            swap(l1,l2);
    }

    cout << "largest @" << l1 << " is " << v[l1] << endl;
    cout << "second  @" << l2 << " is " << v[l2] << endl;

    return 0;
}

