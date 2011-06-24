#include <iostream>
using namespace std;

class Base{
    public: 
        virtual int foo(int k = 10) =0;
};

class Derived1 :public Base{
    public: 
        int foo(int k){
            return k*k;
        }
};

class Derived2 :public Base{
    public: 
        int foo(int k){
            return k*2;
        }
};

int main(){
    int s;
    Derived1 d1;
    Derived2 d2;
    Base *b;
    b = &d1;
    cout << b->foo() << endl;
    b = &d2;
    cout << b->foo() << endl;
    return 0;
}
