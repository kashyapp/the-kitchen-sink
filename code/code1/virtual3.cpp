#include <iostream>
using namespace std;

class Base{
    void stop(){
        cout << "stop base" << endl;
    }
    public:
    virtual void run(){
        stop();
        cout << "run base" << endl;
    }
};

class Derived : public Base {
    void stop(){
        cout << "stop derived" << endl;
    }
    public:
    virtual void run(){
        stop();
        cout << "run derived" << endl;
    }
};


int main(){
    Base * b = new Derived();
    b->run();
    return 0;
}
