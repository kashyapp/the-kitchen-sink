#include <iostream>
#include <exception>
#include <memory>
using namespace std;

#define NL '\n'

class test{
    public:
    test(){
        cerr << "test construct\n";
    }
    void tes(){
        cout << "test\n" ;
    }
    ~test(){
        cerr << "test destruct\n";
    }
};

int main(){
    test foo;
    test *pfoo = new test;

    delete pfoo;
    pfoo=&foo;
    pfoo->tes();
    foo.tes();
    delete pfoo;
    foo.tes();
    pfoo->tes();

    return 0;
}


