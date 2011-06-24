#include <iostream>
#include <algorithm>

using namespace std;

class Foo{
    public:
    template<typename T>
        T fun1(int i){
            return T(i);
        }
    template<typename T>
        int fun2(T i){
            return int(i);
        }
};

int main(){
    Foo foo;
    double d(1.32654);
    int k = foo.fun2(d);
    cout << k << " " << d << endl;

    int j(132654);
    double e = foo.fun1<int>(j);
    cout << j << " " << e << endl;
    return 0;
}
