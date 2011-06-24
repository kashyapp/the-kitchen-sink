#include <iostream>
using namespace std;

class foo{
    int i;
    public: 
    int& geti(){
        return i;
    }
    foo operator++(){
       ++i; 
    }
};

int main(){
    foo fee;
    int &j = fee.geti();
    cout << j << &j << endl;
    return 0;
}
