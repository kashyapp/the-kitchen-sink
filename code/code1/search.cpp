#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &v, int i, int j, int p){
    cout << i << '\t' << j << endl;
    if(i==j){
        if(p==v[i])
            return i;
        else 
            return -1;
    }
    int k = (i+j)/2;
    if(v[i]<=v[j]){
        if(v[k]<p)
            return find(v,k,j,p);
        else if(v[k]>p)
            return find(v,i,k,p);
        else
            return k;
    }
    else{
        int x1,x2;
        int y1,y2;
        if(v[i]<=v[k]){
            x1=i;x2=k;
            y1=k;y2=j;
        }
        else {//if(v[k]<v[j]){
            x1=k;x2=j;
            y1=i;y2=k;
        }
        if(v[x1]<=p && p<=v[x2])
            return find(v,x1,x2,p);
        else
            return find(v,y1,y2,p);
    }
}

int main(){
    int i;
    int p;
    cin >> p;
    vector<int> v;
    while(cin >> i)
        v.push_back(i);
    int j = find(v,0,v.size()-1,p);
    cout << j << endl;
    return 0;
}
