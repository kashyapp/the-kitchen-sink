#include <iostream>
#include <typeinfo>
#define NL '\n'
using namespace std;

class A{
};

class B:public A{
};

template<bool x>
class BT{
};



int main(){
    cout << typeid(A).name() << '\n';
    cout << typeid(BT<false>).name() << '\n';
    cout << typeid(BT<true>).name() << '\n';

    A a;
    cout << typeid(a).name() << NL;
    
    BT<false> bt;
    cout << typeid(bt).name() << NL;
    BT<true> bf;
    cout << typeid(bf).name() << NL;

    B foo;
    B* pfoo = new B;
    A* pbar = new B;

    cout<< typeid(B).name() << '\n'; 
    cout<< typeid(foo).name() << '\n';
    cout<< typeid(pfoo).name() << '\n';
    cout<< typeid(*pfoo).name() << NL;
    cout<< typeid(pbar).name() << NL;
    cout<< typeid(*pbar).name() << NL;
    return 0;
}

