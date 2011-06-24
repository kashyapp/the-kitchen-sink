#include <iostream>
using namespace std;

int main(){
    double i;
    cout.setf(ios::fixed);
    cout.precision(3);
    while(cin >> i) {
        cout << i << endl;
    }

    return 0;
}
