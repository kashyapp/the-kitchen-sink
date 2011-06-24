#include <typeinfo>
#include <iostream>
using namespace std;

typedef const int * ConstIntPointer;
typedef int * const IntPointerConst;
typedef int const * IntConstPointer;

int main(){
    int i = 10;
    int j = 20;
    ConstIntPointer a = &i;
    IntPointerConst b = &i;
    IntConstPointer c = &i;
    
    a = &j;
    //b = &j;
    c = &j;
    //*a = 11;
    *b = 11;
    //*c = 11;

    cout << typeid(a).name() << '\n';
    cout << typeid(b).name() << '\n';
    cout << typeid(c).name() << '\n';
    
    const string &s = string("kashyap");
    cout << typeid(s).name() << s << '\n';

    return 0;
}
