#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int msb(size_t t){
    int i=-1;
    while(t){
        i++;
        t>>=1;
    }
    return i;
} 

template<class T>
void heapsort(vector<T> &v){
    size_t n = v.size();
    cout << n << " " << msb(n) << endl;
    for(int i = n/2 -1; i>=0; --i){
        int j = i;
        while(true){
            int m = j;
            int l = 2*j+1;
            int r = 2*j+2;
            if(l < n && v[l] > v[m])
                m = l;
            if(r < n && v[r] > v[m])
                m = r;
            if(m == j)
                break;
            else{
                int temp = v[m];
                v[m]=v[j];
                v[j] = temp;
                j = m;
            }
        }
    }
}

int main(){
    int k=0;
//    cin >> k;

    int i=0;
    int j;

    vector<int> v;

    while(cin >> j){
       //if(i++ < k)
            v.push_back(j);
    }

    heapsort(v);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout, ", "));    
    cout << endl;

    return 0;
}
