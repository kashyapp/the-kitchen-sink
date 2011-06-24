#include <iostream>
using namespace std;

bool sum(int a[], int n, int s){
    int i = 0;
    int j = n-1;
    while(i!=j){
        int k = a[i] + a[j];
        if (k == s){
            cout << i << " " << j << endl;
            return true;
        } 
        else if (k > s) {
            i++;
        }
        else {
            j--;
        }
    }
    return false;
}

int main(){
    int a[] = {10,9,7,7,6,5,4,1};
    bool b = sum(a,sizeof(a)/sizeof(int),19);
    cout << b << endl;
}
