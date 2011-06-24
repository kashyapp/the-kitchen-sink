#include <iostream>
#include <typeinfo>
#include <memory>
#include <string>
using namespace std;

template<class T>
class Base{
    public:
        Base() :iam("Base"){

        }
        void print() const{

        }
    protected:
        string iam;  
};

class Derived :Base<Derived>{
    public:
        Derived() :iam("Derived") {
        }
    protected:
        string iam;  
};

class A{
    public:
        A(int i) :iam(i){
        }
    protected:
        int iam;
};

class B :public A{
    public:
        B(int i) :iam(i){
        }
};

int main(int argc, char **argv){
    return 0;
}
