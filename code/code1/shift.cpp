#include <iostream>
#include <vector>
using namespace std;

int binsearch(vector<int> &v,int begin,int end,int p){
   if(p<v[begin]||p>v[end])
       return -1;
   int k = (begin+end)/2;
   if(p<v[k])
       return binsearch(v,begin,k,p);
   else if(p>v[k])
       return binsearch(v,k,end,p);
   else
       return k;
}

int search(vector<int> &v, int begin, int end, int p){
    if(end-begin<2){
        if(p==v[begin])
            return begin;
        else if(p==v[end])
            return end;
        else
            return -1;
    }
    if(v[begin] < v[end])
        return binsearch(v,begin,end,p);
    else{
        int k = (begin+end)/2;
        int m1=-1,m2;
        int n1,n2;
        if(v[begin]<v[k]){
            m1=begin;m2=k;
            n1=k;n2=end;
        }
        else if(v[k]<v[end]){
            m1=k;m2=end;
            n1=begin;n2=k;
        }
        if(m1>=0){
            if(v[m1]<=p && p<=v[m2])
                return binsearch(v,m1,m2,p);
            else
                return search(v,n1,n2,p);
        }
        else
            return (search(v,begin,k,p) >? search(v,k,end,p));
    }
}

int main(){
    int p;
    cin >> p;

    vector<int> v;
    int n;
    while( cin >> n )
        v.push_back(n);
    int i = search(v,0,v.size()-1,p);
    cout << i << endl;
    return 0;
}
