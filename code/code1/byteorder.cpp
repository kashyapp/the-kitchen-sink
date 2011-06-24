#include <iostream>
#include <iomanip>
using namespace std;

//short is 16 bits
#define N1 4
#define N2 4
#define MASK 0xF
unsigned short reversebytes(unsigned short n){
    unsigned short ret = 0;
    for(int j=0; j<N1; ++j) {
        int mask = MASK;
        int m = n & mask;
        n = n >> N2; 
        ret = ret << N2;
        ret = ret | m;
        cout << ret << endl;
    }
    return ret;
}

int main(){
    unsigned short n;
    while (cin >> n){
        cout << hex << showbase << n << " " << reversebytes(n) << endl;
    }
}
