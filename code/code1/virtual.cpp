#include <iostream>
using namespace std;

#define NL '\n'

class Base{
    public:
        Base() :iam("base"){}
        void foo(){
            cout<< "foo base: " << iam << NL;
        }
    protected:
        string ibe;
    private:
        string iam;
};
class DerivedA :public Base{
    public:
        DerivedA() :iam("derivedA"){}
        void foo(){
            cout<< "foo A: " << iam << NL;
            bar();
        }
        void bar(){
            cout<< "bar B: " << iam << NL;
        }
    private:
        string iam;
};
class DerivedB :public Base{
    public:
        DerivedB() :iam("derivedB"){}
        void foo(){
            cout<< "foo B: " << iam << NL;
            bar();
        }
        void bar(){
            cout<< "bar B: " << iam << NL;
        }
    private:
        string iam;
};


int main(){
    Base base;
    base.foo();

    DerivedA A;
    DerivedB B;

    Base &rAbase = A;
    Base &rBbase = B;
    rAbase.foo();
    //rAbase.bar();
    rBbase.foo();

    DerivedA *pA = static_cast<>(&rAbase); 
    //rBbase.bar();

    return 0;
}
