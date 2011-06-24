/*
   find the factors of all numbers from 1 through n
   

strategy1:
    something like the eulerian sieve, whenever you find a prime, run it through to the end of list striking off (or dividing) every guy divisible.

strategy2:
    dynamic programming ish solution. 
   */
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num = new int[n];
    int fac = new int[n];
    for(int i=0;i<n;i++){
        num[i] = i+1;
        fac[i] = 2;
    }
    fac[0] = 1;
    for(int i=1; i<n; ++i){
            
    }

}
