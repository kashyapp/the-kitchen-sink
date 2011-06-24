#include <iostream>
using namespace std;

int foo(int k) {
    int i;
    if (cin >> i) {
        int j = foo(k*i); 
        cout << j*k << " ";
        return j*i;
    } else {
        return 1;
    }
}

int main() {
    foo(1);
    cout << endl;
}

