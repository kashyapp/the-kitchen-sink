#include <iostream>
using namespace std;

class Base{
    public:
        virtual 
            ~Base(){
            cout<<"bye bye base\n";
        }
        virtual
        //static 
            void foo(){
            cout << "base\n";
        }
};

class DerivedA :public Base{
    public:
        ~DerivedA(){
            cout << "bye bye derviedA\n";
        }
        virtual
        //static 
            void foo(){
            cout<< "A\n";
        }
};

class DerivedB :public Base{
    public:
        ~DerivedB(){
            cout << "bye bye derviedB\n";
        }
        virtual
        //static 
            void foo(){
            cout<<"B\n";
        }
};


int main(){
    DerivedA A;
    DerivedB B;
    
    A.foo();
    B.foo();

    Base *bA = new DerivedA;
    Base *bB = new DerivedB;
    bA->foo();
    bB->foo();

    delete bA;
    delete bB;

    return 0;
}
