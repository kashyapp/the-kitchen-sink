#include <cassert>
#include <iostream>
using namespace std;


int main(){
    bool foo = true;
    foo &= true;
    assert(foo);
    cout<<foo<<endl;

    foo &= false;
    assert (foo);
    cout<<foo<<endl;

    return 0;
}

